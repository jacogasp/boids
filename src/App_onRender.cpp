//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include <Boids/App.h>

void App::onRender() {
    m_window.clear();

    for (auto &b : m_boids)
        m_window.draw(b);

    m_window.draw(m_gui);
    m_window.display();
}
