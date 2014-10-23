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
#include "MainMenu.h"

MainMenu::MainMenu(sfg::SFGUI *sfgui, Client *client)
:m_sfgui(sfgui), m_client(client), m_visible(false), m_quit(false)
{
}

void MainMenu::show()
{
	// If the main menu shouldn't be visible
	if (m_visible)
		return;
	
	// Create buttons
	auto buttonStart = sfg::Button::Create("Start");
	buttonStart->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&MainMenu::startGameCallBack, this));

	auto buttonQuit = sfg::Button::Create("Quit");
	buttonQuit->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&MainMenu::quitCallBack, this));

	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box->Pack(buttonStart);
	box->Pack(buttonQuit);

	auto mainFrame = sfg::Frame::Create();
	mainFrame->SetLabel("Menu");
	mainFrame->Add(box);

	m_desktop.Add(mainFrame);
	m_visible = true;
}

void MainMenu::close()
{
	if (!m_visible)
		return;
	
	m_desktop.RemoveAll();
	m_visible = false;
}

void MainMenu::handleEvent(sf::Event &event)
{
	m_desktop.HandleEvent(event);
}

void MainMenu::draw()
{
	m_desktop.Update(m_clock.restart().asSeconds());
}

void MainMenu::startGameCallBack()
{
	this->close();
	m_client->connect("localhost", 2323, 2323);
}

void MainMenu::quitCallBack()
{
	m_quit = true;
}

bool MainMenu::isVisible()
{
	return m_visible;
}

bool MainMenu::quitRequested()
{
	return m_quit;
}
