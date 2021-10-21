//
// Created by Jacopo Gasparetto on 20/10/21.
//

#ifndef BOIDS_ENVIRONMENT_H
#define BOIDS_ENVIRONMENT_H

#include "Constants.h"

struct Environment {
    float alignment = Physics::maxAlignment * 0.5f;
    float cohesion = Physics::maxCohesion * 0.5f;
    float separation = Physics::maxSeparation * 0.5f;
    float separationRadius = 1.f;

    Environment() = default;
};

extern Environment environment;

#endif //BOIDS_ENVIRONMENT_H
