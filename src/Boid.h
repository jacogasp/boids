//
// Created by Jacopo Gasparetto on 09/10/21.
//

#ifndef BOIDS_BOID_H
#define BOIDS_BOID_H

#include <SFML/Graphics.hpp>
#include <QuadTree/QuadTree.h>
#include <Vectors/Vectors.h>
#include <iostream>
#include <cmath>
#include "Params.h"

class Boid : public sf::ConvexShape {

private:
    static constexpr float width = 5;
    static constexpr float height = 10;

    sf::Vector2f m_acceleration{ 0, 0 };
    sf::Vector2f m_velocity{ 0.f, 0.f };

    sf::Clock m_clock;
    Params *m_params;


public:
    explicit Boid();

    void setVelocity(const sf::Vector2f &velocity);

    void setParams(Params *params);

public:

    void applyForce(const sf::Vector2f &f);

    void flock(const std::vector<QuadTreeDataPoint<Boid> *> &neighbours);

    void loop(QuadTree<Boid> &quadTree);

private:
    void checkEdges();
};


#endif //BOIDS_BOID_H
