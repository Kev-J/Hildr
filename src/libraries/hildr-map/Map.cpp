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
#include "Map.h"

#include <SFML/OpenGL.hpp>

#include <iostream>

void Map::draw(void)
{
	// Draw a dummy grid
	glMatrixMode(GL_MODELVIEW);
	for (float x = -10.0f ; x < 10.0f ; x+=1.0f) {
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(x,0.0f,10.0f);
			glVertex3f(x,0.0f,-10.0f);
			glVertex3f(10.0f,-0.0f,x);
			glVertex3f(-10.0f,-0.0f,x);
		glEnd();
	}
}
