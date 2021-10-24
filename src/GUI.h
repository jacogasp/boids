//
// Created by Jacopo Gasparetto on 19/10/21.
//

#ifndef BOIDS_GUI_H
#define BOIDS_GUI_H

#include <SFML/Graphics.hpp>
#include <array>

#include "Params.h"
#include "Slider.h"

struct GUI : public sf::Drawable {
private:
    Params m_params;

public:
    std::array<Slider, 3> sliders{
            Slider(Slider::Type::cohesion),
            Slider(Slider::Type::separation),
            Slider(Slider::Type::alignment)
    };

    explicit GUI(Params &params);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //BOIDS_GUI_H
