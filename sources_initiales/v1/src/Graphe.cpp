#include <iostream>
#include <fstream>

#include "Graphe.h"
#include "utils.h"

using namespace std;

Sommet Graphe::ajouterSommet()
{
    Sommet s;
    this->sommets.insert(s);
    return s;
}

std::set<Sommet> Graphe::getSommets() const
{
    return this->sommets;
}

int Graphe::nbSommets() const
{
    return this->sommets.size();
}

Sommet Graphe::source(const Arete &e) const
{
    return this->aretes2Extremites.at(e).first;
}

Sommet Graphe::destination(const Arete &e) const
{
    return this->aretes2Extremites.at(e).second;
}

std::set<Sommet> Graphe::voisins(const Sommet &n) const
{
    std::set<Sommet> voisins;
    for (Arete a : this->sommets2Incidentes.at(n))
    {
        if (this->source(a) == n)
        {
            voisins.insert(this->destination(a));
        }
        else
        {
            voisins.insert(this->source(a));
        }
    }
    return voisins;
}

std::set<Arete> Graphe::incidentes(const Sommet &n) const
{
    return this->sommets2Incidentes.at(n);
}

int Graphe::degre(const Sommet &n) const
{
    return this->incidentes(n).size();
}

void Graphe::supprimerSommet(const Sommet &n)
{
    this->sommets.erase(n);
    for (Arete a : this->incidentes(n))
    {
        this->supprimerArete(a);
    }
}

Arete Graphe::ajouterArete(const Sommet &n1, const Sommet &n2)
{
    Arete a;
    this->aretes.insert(a);
    this->sommets2Incidentes[n1].insert(a);
    this->sommets2Incidentes[n2].insert(a);
    this->aretes2Extremites[a] = make_pair(n1, n2);
    return a;
}

std::set<Arete> Graphe::getAretes() const
{
    return this->aretes;
}

int Graphe::nbAretes() const
{
    return this->aretes.size();
}

void Graphe::supprimerArete(const Arete &e)
{
    this->aretes.erase(e);
    this->sommets2Incidentes[this->source(e)].erase(e);
    this->sommets2Incidentes[this->destination(e)].erase(e);
    this->aretes2Extremites.erase(e);
}

bool Graphe::charger(std::string fichier)
{
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
            int id = stoi(lignes);
            if (idSommet.find(id) != idSommet.end())
                return false; // deux fois le meme identifiant dans le fichier
            Sommet n = ajouterSommet();
            idSommet[id] = n;
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