#include "GrapheValue.h"
#include "Graphe.h"
#include "Arete.h"
#include "Sommet.h"
#include "Coord.h"
#include "utils.h"

#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool GrapheValue::charger(std::string fichier) {
    map<int, Sommet> idSommet;

    // Ajout des sommets
    bool sommetsFinis = false;
    std::ifstream in(fichier.c_str());
    while (!in.eof())
    {
        char ligne[10000];
        in.getline(ligne, 10000);
        string lignes(ligne);
        lignes = lignes.substr(0, lignes.size() - 1);
        if (lignes == "#sommets")
        {
            continue;
        }
        else if (lignes == "#aretes")
        {
            sommetsFinis = true;
        }
        else if (!sommetsFinis)
        {
            vector<string> items;
            decouper(lignes, items, ";");

            if (items.size() != 4) {
                return false;
            } else {
                int id = stoi(items[0]);
                if (idSommet.find(id) != idSommet.end())
                    return false; // deux fois le meme identifiant dans le fichier
                Sommet n = ajouterSommet();
                idSommet[id] = n;
                
                vector<string> position;
                decouper(items[1], position, " ");
                int positionX = stoi(position[0]);
                int positionY = stoi(position[1]);
                Coord coord(positionX, positionY);
                positionSommet(n, coord);

                vector<string> couleur;
                decouper(items[2], couleur, " ");
                int couleurR = stoi(couleur[0]);
                int couleurG = stoi(couleur[1]);
                int couleurB = stoi(couleur[2]);
                int couleurA = stoi(couleur[3]);
                Couleur coul(couleurR, couleurG, couleurB, couleurA);
                couleurSommet(n, coul);

                std::string etiquette = items[3];
                etiquetteSommet(n, etiquette);
            }
        }
        else if (sommetsFinis && lignes != "")
        {
            vector<string> items;
            decouper(lignes, items, " ");
            if (items.size() != 2)
                return false;

            int id1 = stoi(items[0]);
            int id2 = stoi(items[1]);

            // test si les id sont corrects
            if (idSommet.find(id1) == idSommet.end() || idSommet.find(id2) == idSommet.end())
                return false;
            Sommet n1 = idSommet[id1];
            Sommet n2 = idSommet[id2];
            ajouterArete(n1, n2);
        }
    }
    return true;
}

Sommet GrapheValue::ajouterSommet() {
    Sommet s = Graphe::ajouterSommet();
    this->couleurs.changer(s, Couleur(0, 0, 0, 1));
    this->positions.changer(s, Coord(0, 0));
    this->labels.changer(s, "");
    return s;
}

Arete GrapheValue::ajouterArete(const Sommet &n1, const Sommet & n2) {
    Arete a = Graphe::ajouterArete(n1, n2);
    this->couleurs.changer(a, Couleur(0, 0, 0, 1));
    this->labels.changer(a, "");
    return a;
}

void GrapheValue::supprimerSommet(const Sommet &n) {
    Graphe::supprimerSommet(n);
    this->couleurs.supprimer(n);
    this->positions.supprimer(n);
    this->labels.supprimer(n);
}

void GrapheValue::supprimerArete(const Arete &e) {
    Graphe::supprimerArete(e);
    this->couleurs.supprimer(e);
    this->labels.supprimer(e);
}

void GrapheValue::positionSommet(Sommet n, Coord c) {
    this->positions.changer(n, c);
}

Coord GrapheValue::positionSommet(Sommet n) const {
    return this->positions.valeur(n);
}

void GrapheValue::positionsMinMax(Coord & min, Coord & max) {
    min = Coord(0, 0);
    max = Coord(0, 0);
    for (auto s : this->getSommets()) {
        Coord c = this->positions.valeur(s);
        if (c[0] < min[0]) {
            min[0] = c[0];
        }
        if (c[1] < min[1]) {
            min[1] = c[1];
        }
        if (c[0] > max[0]) {
            max[0] = c[0];
        }
        if (c[1] > max[1]) {
            max[1] = c[1];
        }
    }
}

void GrapheValue::couleurSommet(Sommet n, Couleur c) {
    this->couleurs.changer(n, c);
}

Couleur GrapheValue::couleurSommet(Sommet n) {
    return this->couleurs.valeur(n);
}

void GrapheValue::couleurArete(Arete e, Couleur c) {
    this->couleurs.changer(e, c);
}

Couleur GrapheValue::couleurArete(Arete e) {
    return this->couleurs.valeur(e);
}

void GrapheValue::etiquetteSommet(Sommet n, std::string etiquette) {
    this->labels.changer(n, etiquette);
}

std::string GrapheValue::etiquetteSommet(Sommet n) const {
    return this->labels.valeur(n);
}

void GrapheValue::etiquetteArete(Arete e, std::string etiquette) {
    this->labels.changer(e, etiquette);
}

std::string GrapheValue::etiquetteArete(Arete e) const {
    return this->labels.valeur(e);
}