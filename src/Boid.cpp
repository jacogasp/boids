//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include "Boid.h"

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

void Boid::loop(QuadTree<Boid> &quadTree) {
    float deltaT = m_clock.getElapsedTime().asSeconds();

    auto pos = getPosition();

    BoundingBox bb{
            pos.x - visionRange * .5f,
            pos.y - visionRange * .5f,
            pos.x + visionRange * .5f,
            pos.y + visionRange * .5f
    };

    std::vector<QuadTreeDataPoint<Boid> *> result;
    quadTree.query(bb, result);

    // Result will be always of size = 1, because the boid itself
    if (result.size() > 1)
        flock(result);

    // Rotate towards current direction
    auto steeringAngle = 180 - rad2deg(std::atan2(m_velocity.x, m_velocity.y));
    setRotation(steeringAngle);

    // Sum all forces
    m_velocity += m_acceleration;

    // Clip velocity
    limitMagnitude(m_velocity, Physics::maxSpeed);

    // Move the boid
    auto offset = m_velocity * deltaT;
    move(offset);
    checkEdges();

    // Clean up
    m_acceleration *= 0.f;
    m_clock.restart();
}

void Boid::applyForce(const sf::Vector2f &f) {
    m_acceleration += f;
}

void Boid::flock(const std::vector<QuadTreeDataPoint<Boid> *> &neighbours) {

    sf::Vector2f centerOfMass{ 0, 0 };
    sf::Vector2f avgVelocity{0, 0};
    sf::Vector2f avgRepulsion{0, 0};

    int separationCount = 0;

    for (auto &bPtr: neighbours) {
        if (bPtr->data == this) continue;

        auto neighbour = *bPtr->data;

        // Check if in vision range
        if (abs(angleBetween(m_velocity, neighbour.m_velocity)) > visionAngle)
            continue;

        // Cohesion
        centerOfMass += neighbour.getPosition();
        // Alignment
        avgVelocity += neighbour.m_velocity;
        // Repulsion

        float distance{ distanceBetween(getPosition(), neighbour.getPosition()) };

        if (distance < environment.separation * 10.f) {
            avgRepulsion += getPosition() - neighbour.getPosition();
            ++separationCount;
        }
    }

    auto fNumOfBoids = static_cast<float>(neighbours.size() - 1);

    auto cohesionForce = normalize(centerOfMass / fNumOfBoids - getPosition()) * environment.cohesion;
    auto alignmentForce = (avgVelocity / fNumOfBoids - m_velocity) * environment.alignment;

    if (separationCount > 0) {
        auto separationForce = normalize(avgRepulsion / static_cast<float>(separationCount)) * 50.f;
        applyForce(separationForce);
    }

    applyForce(cohesionForce);
    applyForce(alignmentForce);
}

// Bounce agent on edges
void Boid::checkEdges() {

    if (getPosition().x < Resolution::BOUNDING_BOX.x0) {
        setPosition(Resolution::BOUNDING_BOX.x0, getPosition().y);
        m_velocity.x *= -1;
    } else if (getPosition().x > Resolution::BOUNDING_BOX.x1) {
        setPosition(Resolution::BOUNDING_BOX.x1, getPosition().y);
        m_velocity.x *= -1;
    }

    if (getPosition().y < Resolution::BOUNDING_BOX.y0) {
        setPosition(getPosition().x, Resolution::BOUNDING_BOX.y0);
        m_velocity.y *= -1;
    } else if (getPosition().y > Resolution::BOUNDING_BOX.y1) {
        setPosition(getPosition().x, Resolution::BOUNDING_BOX.y1);
        m_velocity.y *= -1;
    }
}