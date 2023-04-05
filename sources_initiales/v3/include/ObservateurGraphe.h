#ifndef OBSERVATEURGRAPHE_H
#define OBSERVATEURGRAPHE_H

#include "Sommet.h"
#include "Arete.h"

class ObservateurGraphe
{
    public:
        void traiterAjout(const Sommet &n) ;
        void traiterAjout(const Arete &e) ;

        void traiterSuppression(const Arete &e) ;
        void traiterSuppression(const Sommet &n) ;

        void traiterProprieteChangee(const Sommet &n) ;
        void traiterProprieteChangee(const Arete &e) ;
};

#endif