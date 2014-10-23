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
#include "Player.h"

#include <iostream>
#include <SFML/OpenGL.hpp>

Player::Player()
:m_posX(0.0f), m_posY(0.0f), m_direction(0.0f),
m_isMovingForward(false), m_isMovingBackward(false),
m_isMovingLeft(false), m_isMovingRight(false)
{
}


void Player::draw()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(m_posX, 0.0f, m_posY);
	glRotatef(m_direction, 0.0f, 1.0f, 0.0f);

	// Draw dummy triangles
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.5f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.5f);
		glVertex3f(0.0f, 0.0f, -0.5f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.5f, 0.0f, 0.5f);
		glVertex3f(-0.5f, 0.0f, -0.5f);
	glEnd();
	glPopMatrix();
}

void Player::update()
{
	// update position
	float x_vector = 0.0f;
	float y_vector = 0.0f;

	if (m_isMovingForward) {
		y_vector += 1.0;
	}
	if (m_isMovingBackward) {
		y_vector -= 1.0;
	}
	if (m_isMovingLeft) {
		x_vector += 1.0;
	}
	if (m_isMovingRight) {
		x_vector -= 1.0;
	}
	
	float norm = m_clockForward.restart().asSeconds()*8.0f; // 8m/s speed

	//Normalize the vector
	float r = sqrt(x_vector*x_vector + y_vector*y_vector);
	if (r != 0) {
		x_vector /= r;
		y_vector /= r;
	}
	
	m_posX += x_vector*norm;
	m_posY += y_vector*norm;
}

void Player::moveForward(bool move)
{
	if (move) {
		m_isMovingForward = true;
	} else {
		m_isMovingForward = false;
	}
}

void Player::moveBackward(bool move)
{
	if (move) {
		m_isMovingBackward = true;
	} else {
		m_isMovingBackward = false;
	}
}

void Player::moveLeft(bool move)
{
	if (move) {
		m_isMovingLeft = true;
	} else {
		m_isMovingLeft = false;
	}

}

void Player::moveRight(bool move)
{
	if (move) {
		m_isMovingRight = true;
	} else {
		m_isMovingRight = false;
	}
}

float Player::getPosX()
{
	return m_posX;
}

float Player::getPosY()
{
	return m_posY;
}

void Player::setDirection(float angle)
{
	m_direction = angle;
}
