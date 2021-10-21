//
// Created by Jacopo Gasparetto on 18/10/21.
//

#include <cassert>
#include <iostream>
#include "../src/VectorsMath.h"


int main() {
    float epsilon = 1e-4;

    auto m1 = getMagnitude(sf::Vector2f {4, 9});
    std::cout << "Magnitude is: " << m1 << '\n';
    assert (m1 - 9.8489 < epsilon);

    auto v = sf::Vector2f{13, 8};
    auto norm = normalize(v);
    std::cout << "Normalized vector: " << norm << '\n';
    assert(norm.x - 0.8517 < epsilon);
    assert(norm.y - 0.5241 < epsilon);


    v = sf::Vector2f{13, 8};
    normalizeInplace(v);
    std::cout << "Normalized vector: " << v << '\n';
    assert(v.x - 0.8517 < epsilon);
    assert(v.y - 0.5241 < epsilon);

    sf::Vector2f a{8, 0};
    sf::Vector2f b{0, 13};

    auto angle = angleBetween(a, b);
    std::cout << "Angle is: " << angle << '\n';

    assert(angle - Physics::PI / 2 < epsilon);

    auto deg = rad2deg(angle);
    std::cout << "Angle in deg is " << deg << '\n';
    assert(deg - 90 < epsilon);

    a = {2, 4};
    b = {6, 12};

    angle = angleBetween(a, b);
    std::cout << "Angle is: " << angle << '\n';

    assert(angle < epsilon);

    v = sf::Vector2f {17, 12};
    auto mag = getMagnitude(v);
    std::cout << "Magnitude: " << mag << '\n';
    assert(mag - 20.8086520467 < epsilon);

    auto v1 = v;
    limitMagnitude(v1, 5.f);
    assert(normalize(v1) == normalize(v));
    std::cout << "v1 magnitude: " << getMagnitude(v1) << '\n';
    assert(getMagnitude(v1) - 5.f < epsilon);


    sf::Vector2f p1{4, 3};
    sf::Vector2f p2{3, -2};
    float distance{ distanceBetween(p1, p2)};
    std::cout << "Distance: " << distance << '\n';
    assert(distance - 5.099f < epsilon);

    std::cout << "\nAll test passed." << std::endl;

    return 0;
}