#include <iostream>

#include "Arete.h"
#include "Sommet.h"

using namespace std;

int Arete::currentId = 0;

Arete::Arete(bool valide)
{
    Arete::currentId++;
    this->id = currentId;
    this->valide = valide;
}

bool Arete::operator<(const Arete &autre) const
{
    return this->id < autre.id;
}

int Arete::getId() const
{
    return this->id;
}

bool Arete::getValide() const
{
    return this->valide;
}
