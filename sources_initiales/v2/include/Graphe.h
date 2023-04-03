#ifndef GRAPHE_H
#define GRAPHE_H

#include "Sommet.h"
#include "Arete.h"

#include <set>
#include <map>

using namespace std;

class Graphe
{

public:
    Sommet ajouterSommet();
    Arete ajouterArete(const Sommet &n1, const Sommet &n2);

    void supprimerSommet(const Sommet &n);
    void supprimerArete(const Arete &e);

    std::set<Sommet> getSommets() const;
    std::set<Arete> getAretes() const;

    std::set<Sommet> voisins(const Sommet &n) const;
    std::set<Arete> incidentes(const Sommet &n) const;

    Sommet source(const Arete &e) const;
    Sommet destination(const Arete &e) const;

    int degre(const Sommet &n) const;

    int nbSommets() const;
    int nbAretes() const;

    bool charger(std::string fichier);

private:
    std::set<Sommet> sommets;
    std::map<Sommet, std::set<Arete> > sommets2Incidentes;
    std::set<Arete> aretes;
    std::map<Arete, std::pair<Sommet, Sommet> > aretes2Extremites;
};

#endif