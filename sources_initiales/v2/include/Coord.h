#ifndef COORD_H
#define COORD_H

class Coord
{
public:
    Coord(bool valide = true); // constructeur
    bool operator<(const Arete &autre) const;
    int getId() const;
    bool getValide() const;

private:
    int id;
    bool valide;
    static int currentId;
};

#endif