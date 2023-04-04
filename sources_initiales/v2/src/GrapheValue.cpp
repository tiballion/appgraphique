#include "GrapheValue.h"
#include "Graphe.h"
#include "Arete.h"
#include "Sommet.h"

using namespace std;

bool GrapheValue::charger(std::string fichier) {
    return Graphe::charger(fichier);
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