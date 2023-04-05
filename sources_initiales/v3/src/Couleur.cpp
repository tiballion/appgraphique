#include <iostream>

#include "Couleur.h"

using namespace std;

Couleur::Couleur()
{
    r = 0;
    g = 0;
    b = 0;
    alpha = 1;
}

Couleur::Couleur(int r, int g, int b, int alpha)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->alpha = alpha;
}

Couleur Couleur::interpoler(const Couleur &c, float valeur)
{
    int r = this->r + (c.r - this->r) * valeur;
    int g = this->g + (c.g - this->g) * valeur;
    int b = this->b + (c.b - this->b) * valeur;
    int alpha = this->alpha + (c.alpha - this->alpha) * valeur;
    return Couleur(r, g, b, alpha);
}

const int& Couleur::operator[](int canal) const
{
    switch (canal)
    {
        case 0:
            return r;
        case 1:
            return g;
        case 2:
            return b;
        case 3:
            return alpha;
        default:
            throw "Erreur: canal invalide";
    }
}

int& Couleur::operator[](int canal)
{
    switch (canal)
    {
        case 0:
            return r;
        case 1:
            return g;
        case 2:
            return b;
        case 3:
            return alpha;
        default:
            throw "Erreur: canal invalide";
    }
}

bool Couleur::operator==(const Couleur & c) const
{
    return (r == c.r && g == c.g && b == c.b);
}