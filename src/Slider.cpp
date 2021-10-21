//
// Created by Jacopo Gasparetto on 19/10/21.
//

#include "Slider.h"

Slider::Slider(Type type) : m_type(type) {
    auto pos = getPosition();
    m_circle.setOrigin(m_circle.getRadius(), m_circle.getRadius());
    m_circle.setPosition(pos.x + m_rect.getSize().x / 2,pos.y + m_rect.getSize().y / 2);
}

sf::Vector2f Slider::getSize() const {
    return {m_rect.getSize().x, m_circle.getRadius() * 2};
}

float Slider::getValue() const {
    return m_value;
}

Slider::Type Slider::getType() const {
    return m_type;
}

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
    isDragging = true;
    auto lowerLimit = 0.f;
    auto upperLimit = m_rect.getSize().x;

    m_circle.setPosition(position.x - getPosition().x, m_circle.getPosition().y);

    if (m_circle.getPosition().x < lowerLimit)
        m_circle.setPosition(0, m_circle.getPosition().y);

    else if (m_circle.getPosition().x > upperLimit) {
        m_circle.setPosition(upperLimit, m_circle.getPosition().y);
    }

    m_value = (m_circle.getPosition().x - lowerLimit) / (upperLimit - lowerLimit);
}