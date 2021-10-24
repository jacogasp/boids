//
// Created by Jacopo Gasparetto on 24/10/21.
//

#ifndef BOIDS_PARAMS_H
#define BOIDS_PARAMS_H


class Params {
private:
    // Window
    int m_windowWidth = 2560;
    int m_windowHeight = 1600;
    float m_margin = 100;

    // Simulation
    int m_numOfBoids = 2000;
    float m_visionRange = 200;
    float m_visionAngle = 270;
    float m_repulsionRange = 20;

    float m_cohesion = 0.f;
    float m_separation = 0.f;
    float m_alignment = 0.f;

public:
    static constexpr float simulationSpeed = 100;
    static constexpr float maxCohesion = 2.f;
    static constexpr float maxSeparation = 2.f;
    static constexpr float maxAlignment = 2.f;
    static constexpr float turnFactor = 2.f;

public:
    // Window
    [[nodiscard]] int windowWidth() const { return m_windowWidth; }

    [[nodiscard]] int windowHeight() const { return m_windowHeight; }

    [[nodiscard]] float margin() const { return m_margin; }

    // Simulation
    [[nodiscard]] int numOfBoids() const { return m_numOfBoids; }

    [[nodiscard]] float visionRange() const { return m_visionRange; }

    [[nodiscard]] float repulsionRange() const { return m_repulsionRange; }

    [[nodiscard]] float visionAngle() const { return m_visionAngle; }

    [[nodiscard]] float cohesion() const { return m_cohesion; }

    [[nodiscard]] float separation() const { return m_separation; }

    [[nodiscard]] float alignment() const { return m_alignment; }

//    [[nodiscard]] float maxCohesion() const { return m_maxCohesion; }
//
//    [[nodiscard]] float maxSeparation() const { return m_maxSeparation; }
//
//    [[nodiscard]] float maxAlignment() const { return m_maxAlignment; }

    void cohesion(float x) { m_cohesion = x; }

    void separation(float x) { m_separation = x; }

    void alignment(float x) { m_alignment = x; }


};


#endif //BOIDS_PARAMS_H
