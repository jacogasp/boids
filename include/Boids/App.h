//
// Created by Jacopo Gasparetto on 09/10/21.
//

#ifndef BOIDS_APP_H
#define BOIDS_APP_H

#include <SFML/Graphics.hpp>
#include <QuadTree/QuadTree.h>
#include <array>
#include <random>

#include "Constants.h"
#include "Boid.h"
#include "GUI.h"

class App {
private:
    sf::Event m_event{};
    std::array<Boid, 100> m_boids{};
    BoundingBox m_boundingBox{ 10, 10, Resolution::WIDTH - 10, Resolution::HEIGHT - 10};
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

};


#endif //BOIDS_APP_H
