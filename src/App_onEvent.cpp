//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include <Boids/App.h>
#include "Environment.h"

void App::onEvent() {
    switch (m_event.type) {
        case sf::Event::Closed:
            m_window.close();
            break;

        case sf::Event::MouseMoved: {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                auto mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));
                updateSliders(mousePosition);
            }
        }
            break;

        case sf::Event::MouseButtonReleased: {
            for (auto &slider: m_gui.sliders) {
                if (slider.isDragging())
                    slider.isDragging(false);
            }
        }
            break;

        default:;
    }
}

void App::updateSliders(const sf::Vector2f &mousePosition) {
    for (auto &slider: m_gui.sliders) {
        if (slider.hit(mousePosition) || slider.isDragging()) {
            slider.updateSlider(mousePosition);

            switch (slider.getType()) {
                case Slider::Type::cohesion:
                    environment.cohesion = Physics::maxCohesion * slider.getValue();
                    std::cout << "Cohesion: " << environment.cohesion << '\n';
                    break;
                case Slider::Type::separation:
                    environment.separation = Physics::maxSeparation * slider.getValue();
                    std::cout << "Separation: " << environment.separation << '\n';
                    break;
                case Slider::Type::alignment:
                    environment.alignment = Physics::maxAlignment * slider.getValue();
                    std::cout << "Alignment: " << environment.alignment << '\n';
                    break;
                default:;
            }
        }
    }
}