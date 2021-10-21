//
// Created by Jacopo Gasparetto on 19/10/21.
//

#include "GUI.h"

GUI::GUI() {
    auto offset = (Resolution::WIDTH - sliders[0].getSize().x) / 3.f;

    for (int i = 0; i < sliders.size(); ++i) {
        sliders.at(i).setPosition({ offset * i + offset / 2.f, 50 });
    }
}


void GUI::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (auto &slider: sliders)
        target.draw(slider);
}

