#ifndef COULEUR_H
#define COULEUR_H

class Couleur
{
    public:
        Couleur(); // constructeur
        Couleur(int r, int g, int b, int alpha); // constructeur 2
        Couleur interpoler(const Couleur &c, float valeur);
        const int& operator[](int canal) const;
        int& operator[](int canal);
        bool operator==(const Couleur & c) const;

    private:
        int r;
        int g;
        int b;
        int alpha;
};

#endif