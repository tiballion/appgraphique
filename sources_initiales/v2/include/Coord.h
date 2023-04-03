#ifndef COORD_H
#define COORD_H

class Coord
{
    public:
        Coord(); // constructeur
        Coord(float x, float y); // constructeur 2
        float norm() const;

        bool operator==(const Coord &c) const ;
        Coord operator+(const Coord &c) const ;
        Coord operator-(const Coord &c) const ;
        Coord& operator+=(const Coord &c);
        Coord& operator-=(const Coord &c);
        Coord operator*(const float &f) const ;
        Coord operator/(const float &f) const;
        Coord& operator*=(const float &f);
        Coord& operator/=(const float &f);

        float & operator[](int dim);
        float operator[](int dim) const;

    private:
        float x;
        float y;
};

#endif