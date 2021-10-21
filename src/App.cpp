//
// Created by Jacopo Gasparetto on 09/10/21.
//

#include <Boids/App.h>

App::App() : m_window(sf::VideoMode(Resolution::WIDTH, Resolution::HEIGHT), "Boids") {
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