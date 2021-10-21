//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include <Boids/App.h>

bool App::onInit() {
    std::default_random_engine generator;
    auto distrib_x = std::uniform_real_distribution<float>(m_boundingBox.x0, m_boundingBox.x1);
    auto distrib_y = std::uniform_real_distribution<float>(m_boundingBox.y0, m_boundingBox.y1);

    auto speed_x_dst = std::uniform_real_distribution<float>(0, 1);
    auto speed_y_dst = std::uniform_real_distribution<float>(0, 1);
    auto direction_dist = std::uniform_real_distribution<float>(0, 1);

    for (auto &boid : m_boids) {
        boid.setPosition(distrib_x(generator), distrib_y(generator));
        auto speed_x = speed_x_dst(generator) * Physics::maxSpeed;
        auto speed_y = speed_y_dst(generator) * Physics::maxSpeed;

        speed_x = direction_dist(generator) > 0.5f ? speed_x : -speed_x;
        speed_y = direction_dist(generator) > 0.5f ? speed_y : -speed_y;

         boid.setVelocity(sf::Vector2f{speed_x, speed_y});
    }

    return true;
}
