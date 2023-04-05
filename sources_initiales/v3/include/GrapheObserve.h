#ifndef GRAPHEOBSERVE_H
#define GRAPHEOBSERVE_H

#include <set>

#include "Sommet.h"
#include "Arete.h"
#include "ObservateurGraphe.h"

using namespace std;

class GrapheObserve
{
protected:
    std::set<ObservateurGraphe *> m_observateurs;

    virtual void notifierAjout(const Sommet &n);
    virtual void notifierAjout(const Arete &e);

    virtual void notifierSuppression(const Arete &e);
    virtual void notifierSuppression(const Sommet &n);

    virtual void notifierProprieteChangee(const Sommet &n);
    virtual void notifierProprieteChangee(const Arete &e);

public:
    GrapheObserve() = default;
    virtual ~GrapheObserve() = default;

    virtual void attacher(ObservateurGraphe *observateur);
    virtual void detacher(ObservateurGraphe *observateur);
};

#endif