//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include "Boid.h"
#include <cassert>

Boid::Boid() {
    setPointCount(3);
    setPoint(0, sf::Vector2f{ width / 2, 0 });
    setPoint(1, sf::Vector2f{ 0, height });
    setPoint(2, sf::Vector2f{ width, height });
    setOrigin(10, 20);
}

void Boid::setVelocity(const sf::Vector2f &velocity) {
    m_velocity = velocity;
}

void Boid::setParams(Params *params) {
    m_params = params;
}


void Boid::loop(QuadTree<Boid> &quadTree) {
    float deltaT = m_clock.getElapsedTime().asSeconds();

    auto pos = getPosition();

    BoundingBox bb{
            pos.x - m_params->visionRange() * .5f,
            pos.y - m_params->visionRange() * .5f,
            pos.x + m_params->visionRange() * .5f,
            pos.y + m_params->visionRange() * .5f
    };

    std::vector<QuadTreeDataPoint<Boid> *> result;
    quadTree.query(bb, result);

    // Result will be always of size = 1, because the boid itself
    if (result.size() > 1)
        flock(result);

    // Sum all forces
    m_velocity += m_acceleration;

    // Clip velocity
    normalize(m_velocity);

    // Rotate towards current direction
    auto currentAngle = getRotation();
    auto desiredAngle = 180.f - sf::rad2deg(std::atan2(m_velocity.x, m_velocity.y));
    auto steeringAngle = currentAngle + (desiredAngle - currentAngle) * deltaT * Params::turnFactor;
    setRotation( steeringAngle);
//    rotate

    // Move the boid
    checkEdges();
    auto offset = m_velocity * Params::simulationSpeed * deltaT;
    move(offset);

    // Clean up
    m_acceleration *= 0.f;
    m_clock.restart();
}

void Boid::applyForce(const sf::Vector2f &f) {
    m_acceleration += f;
}

void Boid::flock(const std::vector<QuadTreeDataPoint<Boid> *> &neighbours) {

    sf::Vector2f centerOfMass{ 0, 0};
    sf::Vector2f avgVelocity{ 0, 0 };
    sf::Vector2f avgRepulsion{ 0, 0 };

    int separationCount = 0;
    int dNumOfBoids = 0;

    assert(neighbours.size() > 1);

    for (auto &bPtr: neighbours) {
        if (bPtr->data == this)
            continue;

        Boid neighbour = *bPtr->data;

        // Check if in vision range
        if (abs(sf::angleBetween(m_velocity, neighbour.m_velocity)) > m_params->visionAngle())
            continue;
        // Cohesion
        centerOfMass += neighbour.getPosition();
        // Alignment
        avgVelocity += neighbour.m_velocity;
        // Repulsion
        float distance{ sf::distanceBetween(getPosition(), neighbour.getPosition()) };

        if (distance < m_params->repulsionRange()) {
            avgRepulsion += getPosition() - neighbour.getPosition();
            ++separationCount;
        }

        ++dNumOfBoids;
    }
    if (dNumOfBoids == 0)
        return;

    auto fNumOfBoids = static_cast<float>(dNumOfBoids);
    centerOfMass /= fNumOfBoids;

//    std::cout << "CM " << centerOfMass;

    auto cohesionForce = sf::normalizeCopy(centerOfMass - getPosition()) * m_params->cohesion();
    auto alignmentForce = sf::normalizeCopy(avgVelocity / fNumOfBoids - m_velocity) * m_params->alignment();

    if (separationCount > 0) {
        auto separationForce = sf::normalizeCopy(avgRepulsion / static_cast<float>(separationCount));
        separationForce *= m_params->separation();
        applyForce(separationForce);
    }

//    std::cout << " CF " << cohesionForce << '\n';
    applyForce(cohesionForce);
    applyForce(alignmentForce);
}

// Bounce agent on edges
void Boid::checkEdges() {
    float turnFactor = 0.05f;

    float leftMargin = m_params->margin();
    float rightMargin = static_cast<float>(m_params->windowWidth()) - m_params->margin();
    float topMargin = m_params->margin();
    float bottomMargin = static_cast<float>(m_params->windowHeight()) - m_params->margin();

    if (getPosition().x < leftMargin) {
//        setPosition(leftMargin, getPosition().y);
        m_velocity.x += turnFactor;
    } else if (getPosition().x > rightMargin) {
//        setPosition(rightMargin, getPosition().y);
        m_velocity.x -= turnFactor;
    }

    if (getPosition().y < topMargin) {
//        setPosition(getPosition().x, topMargin);
        m_velocity.y += turnFactor;
    } else if (getPosition().y > bottomMargin) {
//        setPosition(getPosition().x, bottomMargin);
        m_velocity.y -= turnFactor;
    }
}

