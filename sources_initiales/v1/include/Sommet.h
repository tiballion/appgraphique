#ifndef SOMMET_H
#define SOMMET_H

class Sommet
{
public:
    Sommet(bool valide = true); // constructeur
    bool operator<(const Sommet &autre) const;
    bool operator==(const Sommet &autre) const;
    int getId() const;
    bool getValide() const;

private:
    int id;
    bool valide;
    static int currentId;
};

#endif