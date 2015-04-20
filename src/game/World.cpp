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
#include "World.h"
#include <iostream>

#include "CameraSoldier.h"

World::World()
{
	// Create a camera with type soldier
	m_camera = new CameraSoldier(&m_player);
}

World::~World()
{
	delete m_camera;
}

bool World::load(sf::String mapName)
{
    if (!m_map.load(mapName)) {
        return false;
    }

    return true;
}

void World::draw()
{
	m_camera->updateView(); // Set the camera first

	// Draw map and entities
	m_map.draw();
	m_player.draw();
}

Map* World::getMap()
{
	return &m_map;
}

void World::handleEvent(sf::Event event)
{
	// TODO implement a way to choose the keyboard/joystick layout
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
			case sf::Keyboard::Z :
				m_player.moveForward(true);
			break;
			case sf::Keyboard::S :
				m_player.moveBackward(true);
			break;
			case sf::Keyboard::Q :
				m_player.moveLeft(true);
			break;
			case sf::Keyboard::D :
				m_player.moveRight(true);
			break;
			default:
			break;
		}
	}

	if (event.type == sf::Event::KeyReleased) {
		switch (event.key.code) {
			case sf::Keyboard::Z :
				m_player.moveForward(false);
			break;
			case sf::Keyboard::S :
				m_player.moveBackward(false);
			break;
			case sf::Keyboard::Q :
				m_player.moveLeft(false);
			break;
			case sf::Keyboard::D :
				m_player.moveRight(false);
			break;
			default:
			break;
		}
	}

	if (event.type == sf::Event::MouseMoved) {
		float a = 640/2 - event.mouseMove.x;
		float b = event.mouseMove.y - 480/2;
		float angle = atanf(b/a)*180.0f/M_PI;

		if ((a < 0) && (b > 0)) { angle += 180.0f; }
		else if ((a < 0) && (b < 0)) { angle += 180.0f; }
		else if ((a > 0) && (b < 0)) { angle += 360.f; }

		m_player.setDirection(angle);
	}
}

void World::update()
{
	m_player.update();
}
