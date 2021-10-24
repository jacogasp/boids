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
#include "Constants.h"
#include "Environment.h"

class Boid : public sf::ConvexShape {

private:
    static constexpr float visionAngle = 90 * Physics::PI / 180;
    static constexpr int   visionRange = 50;
    static constexpr float repulsionRange = 30;

    static constexpr float width = 10;
    static constexpr float height = 20;

    sf::Vector2f m_acceleration{ 0, 0 };
    sf::Vector2f m_velocity{ 0.f, 0.f };

    sf::Clock m_clock;

public:
    Boid();

    void setVelocity(const sf::Vector2f &velocity);

public:

    void applyForce(const sf::Vector2f &f);

    void flock(const std::vector<QuadTreeDataPoint<Boid> *> &neighbours);

    void loop(QuadTree<Boid> &quadTree);

private:
    void checkEdges();
};


#endif //BOIDS_BOID_H
