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
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>

class Player {
	public:
		Player();

		void moveForward(bool move);
		void moveBackward(bool move);
		void moveLeft(bool move);
		void moveRight(bool move);

		void update(void);
		void draw(void);
		float getPosX();
		float getPosY();
		void setDirection(float angle); // In degrees
	private:
		float m_posX, m_posY; // in meters
		float m_direction; // in degrees
		bool m_isMovingForward, m_isMovingBackward;
		bool m_isMovingLeft, m_isMovingRight;
		sf::Clock m_clockForward;
};

#endif
