//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include <Boids/App.h>

void App::onLoop() {

    // Reinitialize QuadTree each frame and populate it
    QuadTree<Boid> quadTree{ m_boundingBox };

    for (auto &b: m_boids) {
        auto point = QuadTreeDataPoint<Boid>{ b.getPosition().x, b.getPosition().y, &b };
        quadTree.insert(point);
    }

    // Update each boid
    for (auto &b: m_boids) {
        b.loop(quadTree);
    }
}
