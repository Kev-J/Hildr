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
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SFGUI/SFGUI.hpp>

#include "Client.h"

class MainMenu {
	public:
		MainMenu(sfg::SFGUI *sfgui, Client *client);
		void show();
		void close();
		void draw();
		void handleEvent(sf::Event &event);
		void startGameCallBack();
		void quitCallBack();
		bool isVisible();
		bool quitRequested();
	
	private:
		sfg::SFGUI *m_sfgui;
		Client *m_client;
		sf::Clock m_clock;
		sfg::Desktop m_desktop;
		bool m_visible;
		bool m_quit;
};

#endif
