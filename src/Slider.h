//
// Created by Jacopo Gasparetto on 19/10/21.
//

#ifndef BOIDS_SLIDER_H
#define BOIDS_SLIDER_H

#include <SFML/Graphics.hpp>

class Slider : public sf::Drawable, public sf::Transformable {
public:
    enum Type {
        cohesion,
        alignment,
        separation,
    };

private:
    Slider::Type m_type;
    sf::CircleShape m_circle{ 12 };
    sf::RectangleShape m_rect;
    float m_lowerLimit = 0.f;
    float m_upperLimit = 200.f;

    bool m_bIsDragging = false;
    float m_value = 0.f;

public:

    // Constructors
    explicit Slider(Type type, float width = 200);

    // Getters
    sf::Vector2f getSize() const;

    float getValue() const;

    Slider::Type getType() const;

    bool isDragging() const;

    // Setters
    void isDragging(bool value);

    // Helpers
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool hit(const sf::Vector2f &position);

    void updateSlider(const sf::Vector2f &position);
};


#endif //BOIDS_SLIDER_H
