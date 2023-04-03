#ifndef ARRETE_H
#define ARRETE_H
#include "Sommet.h"

class Arete
{
public:
    Arete(bool valide = true); // constructeur
    bool operator<(const Arete &autre) const;
    int getId() const;
    bool getValide() const;

private:
    int id;
    bool valide;
    static int currentId;
};

#endif