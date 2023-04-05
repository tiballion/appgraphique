#ifndef APPLI_H
#define APPLI_H
#include <SFML/Graphics.hpp>
#include "GrapheValue.h"
#include "Sommet.h"
#include "Arete.h"
#include "ObservateurGraphe.h"

class Appli : public ObservateurGraphe
{
public:
    Appli(unsigned int largeur, unsigned int hauteur);

    void setGraphe(GrapheValue &g);

    bool running() const;
    void exec();

    void traiterAjout(const Sommet &n) override;
    void traiterAjout(const Arete &e) override;

    void traiterSuppression(const Arete &e) override;
    void traiterSuppression(const Sommet &n) override;

    void traiterProprieteChangee(const Sommet &n) override;
    void traiterProprieteChangee(const Arete &e) override;

private:
    sf::View m_vue;
    sf::RenderWindow m_fenetre;
    sf::Font m_font;

    sf::CircleShape m_sommet;
    sf::Text m_etiquette;
    GrapheValue *m_g;

    bool m_montre_etiquette;
    bool m_interpoler_couleurs;

    static const float RAYON;
    static const std::string FICHIER_FONT;

    unsigned int m_largeur, m_hauteur;

    void traiter_evenements();
    void dessiner();
};

#endif // APPLI_H
