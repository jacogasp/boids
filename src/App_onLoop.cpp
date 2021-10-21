//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include <Boids/App.h>

void App::onLoop() {

    QuadTree<Boid> quadTree{ m_boundingBox };

    for (auto &b: m_boids) {
        auto pos = b.getPosition();
        auto point = QuadTreeDataPoint<Boid>{ pos.x, pos.y, &b };
        quadTree.insert(point);
    }
    for (auto &b: m_boids) {
        b.loop(quadTree);
    }
}
