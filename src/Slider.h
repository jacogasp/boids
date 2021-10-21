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
    sf::CircleShape m_circle{ 12 };
    sf::RectangleShape m_rect{ { 200, 2 } };

    float m_value = 0.5;
    Slider::Type m_type;

public:

    bool isDragging = false;

    explicit Slider(Type type);

    sf::Vector2f getSize() const;

    float getValue() const;

    Slider::Type getType() const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool hit(const sf::Vector2f &position);

    void updateSlider(const sf::Vector2f &position);
};


#endif //BOIDS_SLIDER_H
