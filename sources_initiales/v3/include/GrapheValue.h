#ifndef GRAPHEVALUE_H
#define GRAPHEVALUE_H

#include "Graphe.h"
#include "Coord.h"
#include "Couleur.h"
#include "Sommet.h"
#include "Arete.h"
#include "Propriete.hpp"
#include "GrapheObserve.h"

#include <string>

using namespace std;

class GrapheValue : public Graphe, public GrapheObserve {
    public:
        bool charger(std::string fichier) override ;
        Sommet ajouterSommet();
        Arete ajouterArete(const Sommet &n1, const Sommet & n2) ;
        void supprimerSommet(const Sommet &n) ;
        void supprimerArete(const Arete &e) ;
        void positionSommet(Sommet n, Coord c) ;
        Coord positionSommet(Sommet n) const ;
        void positionsMinMax(Coord & min, Coord & max) ;
        void couleurSommet(Sommet n, Couleur c) ;
        Couleur couleurSommet(Sommet n) ;
        void couleurArete(Arete e, Couleur c) ;
        Couleur couleurArete(Arete e) ;
        void etiquetteSommet(Sommet n, std::string etiquette) ;
        std::string etiquetteSommet(Sommet n) const ;
        void etiquetteArete(Arete e, std::string etiquette) ;
        std::string etiquetteArete(Arete e) const ;

    private:
        Propriete<Couleur> couleurs;
        Propriete<Coord> positions;
        Propriete<std::string> labels;
};

#endif