//
// Created by Jacopo Gasparetto on 19/10/21.
//

#include "Slider.h"

// Constructors
Slider::Slider(Type type, float width) :
        m_type(type),
        m_rect({ width, 2 }),
        m_upperLimit(width) {

    auto pos = getPosition();
    m_circle.setOrigin(m_circle.getRadius(), m_circle.getRadius());
    m_circle.setPosition(pos.x, pos.y + m_rect.getSize().y / 2);
}

// Getters
sf::Vector2f Slider::getSize() const {
    return { m_rect.getSize().x, m_circle.getRadius() * 2 };
}

float Slider::getValue() const {
    return m_value;
}

Slider::Type Slider::getType() const {
    return m_type;
}

bool Slider::isDragging() const {
    return m_bIsDragging;
}

// Setters
void Slider::isDragging(bool value) {
    m_bIsDragging = value;
}

// Helpers
void Slider::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_rect, states);
    target.draw(m_circle, states);
}

bool Slider::hit(const sf::Vector2f &position) {
    return
            position.x >= getPosition().x &&
            position.x <= getPosition().x + m_rect.getSize().x &&
            position.y >= getPosition().y - m_circle.getRadius() &&
            position.y <= getPosition().y + m_circle.getRadius();
}

void Slider::updateSlider(const sf::Vector2f &position) {
    isDragging(true);

    m_circle.setPosition(position.x - getPosition().x, m_circle.getPosition().y);

    // Bound the slider between its size
    if (m_circle.getPosition().x < m_lowerLimit)
        m_circle.setPosition(0, m_circle.getPosition().y);

    else if (m_circle.getPosition().x > m_upperLimit) {
        m_circle.setPosition(m_upperLimit, m_circle.getPosition().y);
    }

    // Update slider value
    m_value = (m_circle.getPosition().x - m_lowerLimit) / (m_upperLimit - m_lowerLimit);
}