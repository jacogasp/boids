//
// Created by Jacopo Gasparetto on 19/10/21.
//

#include "GUI.h"

GUI::GUI(Params &params) : m_params(params) {
    auto offset = (static_cast<float>(m_params.windowWidth()) - sliders[0].getSize().x) / 3.f;

    for (size_t i = 0; i < sliders.size(); ++i) {
        sliders.at(i).setPosition({ offset * i + offset / 2.f, 50 });
    }
}


void GUI::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (auto &slider: sliders)
        target.draw(slider, states);
}

