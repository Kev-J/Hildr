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
#include "Client.h"

Client::Client()
:m_connected(false)
{
}

bool Client::connect(std::string host, unsigned int tcpPort, unsigned int udpPort)
{
	// TODO implement connection
	m_connected = true;
	return m_connected;
}

bool Client::isConnected()
{
	return m_connected;
}

World* Client::getWorld()
{
	return &m_world;
}
