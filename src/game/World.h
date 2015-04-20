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
#ifndef WORLD_H
#define WORLD_H

#include <SFML/Window.hpp>

#include <hildr-map/Map.h>

#include "Camera.h"
#include "Player.h"

class World {
	public:
		World();
		~World();

		bool load(sf::String mapName);

		/* Draw the world to the screen */
		void draw(void);
		
		/* Update all entities status and player positions */
		void update(void);

		/* Handle keyboard, mouse, joystick ... */
		void handleEvent(sf::Event event);

		/* Accessors */
		Map* getMap(void);

	private:
		Map m_map;
		Camera *m_camera;
		Player m_player;
};

#endif
