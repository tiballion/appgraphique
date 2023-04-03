#include <iostream>

#include "Sommet.h"

using namespace std;

int Sommet::currentId = 0;

Sommet::Sommet(bool valide)
{
    Sommet::currentId++;
    this->id = currentId;
    this->valide = valide;
}

bool Sommet::operator<(const Sommet &autre) const
{
    return this->id < autre.id;
}

bool Sommet::operator==(const Sommet &autre) const
{
    return this->id == autre.id;
}

int Sommet::getId() const
{
    return this->id;
}

bool Sommet::getValide() const
{
    return this->valide;
}