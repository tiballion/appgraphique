#include "Appli.h"
#include "GrapheValue.h"
#include "Arete.h"
#include "Sommet.h"
#include "SFML/Window.hpp"
#include <iostream>

using namespace std;

Appli::Appli(unsigned int largeur, unsigned int hauteur) {
    m_fenetre.create(sf::VideoMode(largeur, hauteur), "googoogaga");
    m_fenetre.setFramerateLimit(60);
    m_fenetre.setVerticalSyncEnabled(true);
    m_fenetre.setKeyRepeatEnabled(false);

    sf::View m_vue;
    m_fenetre.setView(m_vue);

    m_sommet = sf::CircleShape(5);
}

void Appli::setGraphe(GrapheValue &g) {
    m_g = &g;
}

bool Appli::running() const {
    return m_fenetre.isOpen();
}

void Appli::exec() {
    traiter_evenements();
    dessiner();
}

void Appli::traiter_evenements() {
    sf::Event event;
    while (m_fenetre.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                m_fenetre.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    m_fenetre.close();
                if (event.key.code == sf::Keyboard::Space)
                    m_montre_etiquette = !m_montre_etiquette;
                if (event.key.code == sf::Keyboard::I)
                    m_interpoler_couleurs = !m_interpoler_couleurs;
                break;
            default:
                break;
        }
    }
}

void Appli::dessiner() {
    m_fenetre.clear(sf::Color::White);
    
    // dessiner les aretes
    for (Arete a : m_g->getAretes()) {
        sf::Vertex ligne[] = {
            sf::Vertex(sf::Vector2f(m_g->positionSommet(m_g->source(a))[0] + 5, m_g->positionSommet(m_g->source(a))[1] + 5)),
            sf::Vertex(sf::Vector2f(m_g->positionSommet(m_g->destination(a))[0] + 5, m_g->positionSommet(m_g->destination(a))[1] + 5))
        };
        ligne[0].color = sf::Color(m_g->couleurArete(a)[0], m_g->couleurArete(a)[1], m_g->couleurArete(a)[2]);
        ligne[1].color = sf::Color(m_g->couleurArete(a)[0], m_g->couleurArete(a)[1], m_g->couleurArete(a)[2]);
        m_fenetre.draw(ligne, 2, sf::Lines);
    }

    // dessiner les sommets
    for (Sommet s : m_g->getSommets()) {
        m_sommet.setPosition(m_g->positionSommet(s)[0], m_g->positionSommet(s)[1]);
        m_sommet.setFillColor(sf::Color(m_g->couleurSommet(s)[0], m_g->couleurSommet(s)[1], m_g->couleurSommet(s)[2]));
        m_sommet.setOutlineThickness(1);
        m_sommet.setOutlineColor(sf::Color(0, 0, 0));
        m_fenetre.draw(m_sommet);
    }

    // dessiner les etiquettes
    if (m_montre_etiquette) {
        for (Sommet s : m_g->getSommets()) {
            m_etiquette.setString(m_g->etiquetteSommet(s));
            m_etiquette.setPosition(m_g->positionSommet(s)[0] + 10, m_g->positionSommet(s)[1] + 10);
            m_fenetre.draw(m_etiquette);
        }
    }

    m_fenetre.display();
}