/*
 * Copyright 2014 Kevin JOLY <joly.kevin25@gmail.com>
 *
 * This file is part of Hildr.
 * 
 * Hildr is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Hildr is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Hildr.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */
#include "Game.h"
#include <sstream>
#include <SFML/OpenGL.hpp>

Game::Game()
{
    // Init rendering window
    m_window = new sf::RenderWindow(sf::VideoMode(640, 480), "Hildr");
    m_window->resetGLStates();

    // Init OpenGL
    glMatrixMode(GL_PROJECTION);
    gluPerspective(90.0f, (GLfloat)640/(GLfloat)480, 1.0f, 1000.0f);
    glEnable(GL_DEPTH_TEST);

    m_client = new Client();

    // Show main menu
    m_mainMenu = new MainMenu(&m_sfgui, m_client);
    m_mainMenu->show();

    m_fpsClock.restart();
}

Game::~Game()
{
    delete m_client;
    delete m_mainMenu;
    delete m_window;
}

bool Game::frame()
{
    static unsigned int frames = 0;
    World *world = m_client->getWorld();

    sf::Event event;

    // Read all events
    while (m_window->pollEvent(event)) {
        if (m_mainMenu->isVisible()) {
            m_mainMenu->handleEvent(event); // Send the events to the main menu
        }

        if (m_client->isConnected()) { // If user is in game
            world->handleEvent(event);
        }

        if ((event.type == sf::Event::Closed) || (m_mainMenu->quitRequested())) {
            m_window->close(); // Close the game
        }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (m_mainMenu->isVisible()) { // if The main menu is displayed
        m_mainMenu->draw(); // Draw the main menu
    }

    // Clear the window to be drawn
    m_window->clear();

    m_sfgui.Display(*m_window); // Draw the GUI on the window

    if (m_client->isConnected()) {
        // The player is in game
        world->update();
        world->draw();
    }

    // Display the new window
    m_window->display();

    // Compute FPS and print it to the title of the window
    float deltaFps = m_fpsClock.getElapsedTime().asSeconds();

    frames++;
    if (deltaFps >= 1.0) {
        m_fpsClock.restart();
        float fps = (float)frames*deltaFps;
        std::ostringstream oss;
        oss << fps;
        m_window->setTitle("Hildr [" + oss.str() + " FPS]");
        frames = 0;
    }

    return m_window->isOpen();
}
