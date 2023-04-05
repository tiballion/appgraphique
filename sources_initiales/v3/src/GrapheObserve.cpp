#include "GrapheObserve.h"
#include "ObservateurGraphe.h"
#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"

using namespace std;

void GrapheObserve::attacher(ObservateurGraphe *observateur) {
    m_observateurs.insert(observateur);
}

void GrapheObserve::detacher(ObservateurGraphe *observateur) {
    m_observateurs.erase(observateur);
}

void GrapheObserve::notifierAjout(const Sommet &n) {
    for (auto it = m_observateurs.begin(); it != m_observateurs.end(); ++it) {
        (*it)->traiterAjout(n);
    }
}

void GrapheObserve::notifierSuppression(const Sommet &n) {
    for (auto it = m_observateurs.begin(); it != m_observateurs.end(); ++it) {
        (*it)->traiterSuppression(n);
    }
}

void GrapheObserve::notifierAjout(const Arete &e) {
    for (auto it = m_observateurs.begin(); it != m_observateurs.end(); ++it) {
        (*it)->traiterAjout(e);
    }
}

void GrapheObserve::notifierSuppression(const Arete &e) {
    for (auto it = m_observateurs.begin(); it != m_observateurs.end(); ++it) {
        (*it)->traiterSuppression(e);
    }
}

void GrapheObserve::notifierProprieteChangee(const Sommet &n) {
    for (auto it = m_observateurs.begin(); it != m_observateurs.end(); ++it) {
        (*it)->traiterProprieteChangee(n);
    }
}

void GrapheObserve::notifierProprieteChangee(const Arete &e) {
    for (auto it = m_observateurs.begin(); it != m_observateurs.end(); ++it) {
        (*it)->traiterProprieteChangee(e);
    }
}
