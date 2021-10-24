//
// Created by Jacopo Gasparetto on 09/10/21.
//

#ifndef BOIDS_CONSTANTS_H
#define BOIDS_CONSTANTS_H

#include <QuadTree/QuadTree.h>

namespace Resolution {
    constexpr int WIDTH = 1280;
    constexpr int HEIGHT = 800;
    constexpr BoundingBox BOUNDING_BOX { 30, 30, WIDTH - 30, HEIGHT - 30};
}

namespace Physics {
    constexpr float maxSpeed = 100;
    constexpr float PI = 3.1415926535f;
    constexpr float maxCohesion = 10.f;
    constexpr float maxAlignment = 2.f;
    constexpr float maxSeparation = 2.f;
}

#endif //BOIDS_CONSTANTS_H
