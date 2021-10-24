//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include <Boids/App.h>

App::App() :
m_window(sf::VideoMode(m_params.windowWidth(), m_params.windowHeight()), "Boids"),
m_gui(m_params)
{
    m_window.setVerticalSyncEnabled(true);
}


int App::run() {
    if (!onInit())
        return -1;

    while(m_window.isOpen()) {
        while(m_window.pollEvent(m_event)) {
            onEvent();
        }

        onLoop();
        onRender();
    }

    onCleanUp();
    return 0;
}