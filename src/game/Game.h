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
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>

#include "MainMenu.h"
#include "Client.h"
#include "World.h"

class Game {
	public:
		Game();
		~Game();
		bool frame(void);
	private:
		sfg::SFGUI m_sfgui;
		sf::RenderWindow *m_window;

		MainMenu *m_mainMenu;

		Client *m_client;
		sf::Clock m_fpsClock;
};

#endif
