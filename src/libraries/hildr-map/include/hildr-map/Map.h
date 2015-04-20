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
#ifndef MAP_H
#define MAP_H

#include <vector>

#include <SFML/System.hpp>
#include <xercesc/dom/DOM.hpp>

#include "Texture.h"

class Map {
    public:
        Map(void);
        bool load(sf::String mapName);
        void unload(void);
        void draw();

    private:
        void loadTextures(xercesc::DOMNode *textureNode);

    private:
        sf::String m_mapName;
        bool m_loaded;
        std::vector<Texture*> m_textures;
};

#endif
