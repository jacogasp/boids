//
// Created by Jacopo Gasparetto on 10/10/21.
//

#ifndef BOIDS_VECTORSMATH_H
#define BOIDS_VECTORSMATH_H

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>
#include "Constants.h"

template<typename T>
T rad2deg(T angle) {
    return angle * 180.f / Physics::PI;
}

template <typename T>
T getMagnitude(const sf::Vector2<T> & v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
sf::Vector2<T> normalize(const sf::Vector2<T> &v) {
    sf::Vector2<T> u {v};
    auto norm = getMagnitude(u);
    if (norm == 0) return u;

    u.x /= norm;
    u.y /= norm;
    return u;
}

template <typename T>
void normalizeInplace(sf::Vector2<T> &v) {
    auto norm = getMagnitude(v);
    if (norm == 0) return;
    v /= norm;
}

template <typename T>
void setMagnitude(sf::Vector2<T> &v, T magnitude) {
    normalizeInplace(v);
    v *= magnitude;
}

template <typename T>
void limitMagnitude(sf::Vector2<T> &v, T magnitude) {
    if (getMagnitude(v) > magnitude)
        setMagnitude(v, magnitude);
}

template <typename T>
T angleBetween(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
    auto a = getMagnitude(v1);
    auto b = getMagnitude(v2);
    auto d = getMagnitude(v1 - v2);

    auto a_dot_b = (a * a + b * b - d * d) / 2;
    return acos(a_dot_b / (a * b));
}

template <typename T>
float distanceBetween(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
    return sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}


template <typename T>
std::ostream & operator<<(std::ostream &out, const sf::Vector2<T> v) {
    out << "x: " << v.x << ", y: " << v.y;
    return out;
}

#endif //BOIDS_VECTORSMATH_H
