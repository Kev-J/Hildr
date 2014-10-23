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
#include <SFML/OpenGL.hpp>

#include "CameraSoldier.h"

CameraSoldier::CameraSoldier(Player *player)
:m_player(player)
{

}

void CameraSoldier::updateView()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(m_player->getPosX(), CAMERA_HEIGHT, m_player->getPosY(), // Follow the player location
		m_player->getPosX(), 0.0, m_player->getPosY(), // Follow the player location
		0.0, 0.0, 1.0); // The camera axis cannot be the viewing direction
}
