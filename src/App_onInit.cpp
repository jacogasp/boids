//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include <Boids/App.h>

bool App::onInit() {
    std::default_random_engine generator;
    auto distrib_x = std::uniform_real_distribution<float>(m_boundingBox.x0, m_boundingBox.x1);
    auto distrib_y = std::uniform_real_distribution<float>(m_boundingBox.y0, m_boundingBox.y1);

    auto speed_x_dst = std::uniform_real_distribution<float>(-1, 1);
    auto speed_y_dst = std::uniform_real_distribution<float>(-1, 1);

    m_boids.resize(m_params.numOfBoids());

    for (auto &boid : m_boids) {
        boid.setParams(&m_params);
        boid.setPosition(distrib_x(generator), distrib_y(generator));

        auto speed_x = speed_x_dst(generator);
        auto speed_y = speed_y_dst(generator);
         boid.setVelocity(sf::Vector2f{speed_x, speed_y});
    }

    return true;
}
