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
#include "Game.h"

#include <SFML/OpenGL.hpp>
#include <hildr-tools/hildr-tools.h>

int main(int argc, char **argv)
{
	Game game;

        if (!HildrTools::XmlConfig::initializeSubsystem()) {
            std::cerr << "Unable to initialize" << std::endl;
            return -1;
        }

        /* Start game loop */
	while (game.frame())
            ;

        HildrTools::XmlConfig::terminateSubsystem();

	return 0;
}
