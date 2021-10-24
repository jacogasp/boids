//
// Created by Jacopo Gasparetto on 09/10/21.
//

#ifndef BOIDS_APP_H
#define BOIDS_APP_H

#include <SFML/Graphics.hpp>
#include <QuadTree/QuadTree.h>
#include <vector>
#include <random>

#include "Boid.h"
#include "GUI.h"

class App {
private:
    Params m_params{};
    sf::Event m_event{};
    std::vector<Boid> m_boids;
    BoundingBox m_boundingBox{ m_params.margin(), m_params.margin(),
                               static_cast<float>(m_params.windowWidth()) - m_params.margin(),
                               static_cast<float>(m_params.windowHeight()) - m_params.margin()};
    sf::RenderWindow m_window;
    GUI m_gui;

public:
    App();

    int run();

private:
    bool onInit();

    void onEvent();

    void onLoop();

    void onRender();

    void onCleanUp();

private:
    void updateSliders(const sf::Vector2f &mousePosition);
};


#endif //BOIDS_APP_H
