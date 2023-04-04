#ifndef PROPRIETE_H
#define PROPRIETE_H

#include "Sommet.h"
#include "Arete.h"

#include <map>

template<typename T>
class Propriete {
    public :
        void changer(Sommet n, const T &val);
        void changer(Arete e, const T &val);
        const T & valeur(Sommet n) const;
        const T & valeur(Arete e) const;
        void supprimer(Sommet n);
        void supprimer(Arete e);

    private :
        std::map<Sommet, T> associationSommetT;
        std::map<Arete, T> associationAreteT;
};

template<typename T>
void Propriete<T>::changer(Sommet n, const T &val) {
    Propriete<T>::associationSommetT[n] = val;
}

template<typename T>
void Propriete<T>::changer(Arete e, const T &val) {
    Propriete<T>::associationAreteT[e] = val;
}

template<typename T>
const T & Propriete<T>::valeur(Sommet n) const {
    return Propriete<T>::associationSommetT.at(n);
}

template<typename T>
const T & Propriete<T>::valeur(Arete e) const {
    return Propriete<T>::associationAreteT.at(e);
}

template<typename T>
void Propriete<T>::supprimer(Sommet n) {
    Propriete<T>::associationSommetT.erase(n);
}

template<typename T>
void Propriete<T>::supprimer(Arete e) {
    Propriete<T>::associationAreteT.erase(e);
}

#endif
