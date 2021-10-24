//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include <Boids/App.h>

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
                    m_params.cohesion(Params::maxCohesion * slider.getValue());
                    std::cout << "Cohesion: " << m_params.cohesion() << '\n';
                    break;
                case Slider::Type::separation:
                    m_params.separation(Params::maxSeparation * slider.getValue());
                    std::cout << "Separation: " << m_params.separation() << '\n';
                    break;
                case Slider::Type::alignment:
                    m_params.alignment(Params::maxAlignment * slider.getValue());
                    std::cout << "Alignment: " << m_params.alignment() << '\n';
                    break;
                default:;
            }
        }
    }
}