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

#include <hildr-tools/hildr-tools.h>

Map::Map()
:m_loaded(false)
{
}

bool Map::load(sf::String mapName)
{
    if (m_loaded)
        unload();

    sf::String xmlFilepath = HildrTools::mapPath+"/"+mapName+"/"+mapName+".xml";
    m_mapName = mapName;

    HildrTools::XmlConfig mapDesc(xmlFilepath);

    if (!mapDesc.parse())
        return false;

    xercesc::DOMNode* doc = mapDesc.getDocumentElement();

    if (doc == 0) {
        std::cerr << "Wrong file  " << xmlFilepath.toAnsiString() << std::endl;
        return false;
    }

    if (doc->getFirstChild() == 0) {
        std::cerr << "Wrong file  " << xmlFilepath.toAnsiString() << std::endl;
        return false;
    }

    xercesc::DOMNodeList *texturesNode = mapDesc.getChildrenNode(doc->getFirstChild(), "textures");

    if ((texturesNode != 0) && (texturesNode->getLength() > 0)) {
        xercesc::DOMNodeList *textures = mapDesc.getChildrenNode(texturesNode->item(0), "texture");
        for (int i = 0 ; i < textures->getLength() ; i++) {
            loadTextures(textures->item(i));
        }
    }

    m_loaded = true;

    return true;
}

void Map::loadTextures(xercesc::DOMNode *textureNode)
{
    xercesc::DOMNamedNodeMap* attributes = textureNode->getAttributes();

    if (attributes != 0) {
        sf::String textureName = "";
        sf::String textureFilePath = "";

        for (int i = 0 ; i < attributes->getLength() ; i++) {

            const XMLCh* nameXML = attributes->item(i)->getNodeName();
            char* nameCh = xercesc::XMLString::transcode(nameXML);
            sf::String name = nameCh;
            xercesc::XMLString::release( &nameCh);

            if (name == "name") {
                const XMLCh* valueXML = attributes->item(i)->getNodeValue();
                char* valueCh = xercesc::XMLString::transcode(valueXML);
                textureName = valueCh;
                xercesc::XMLString::release( &valueCh);
            }
        }

        if (textureName == "")
            return; //Invalid texture name

        const XMLCh* pathXML = textureNode->getTextContent();
        char* pathCh = xercesc::XMLString::transcode(pathXML);
        textureFilePath = pathCh;
        xercesc::XMLString::release(&pathCh);

        if (textureFilePath == "")
            return; //Invalid texture path

        Texture *tex = new Texture();
        if (!tex->load(textureName.toAnsiString(), HildrTools::mapPath+"/"+m_mapName+"/textures/"+textureFilePath.toAnsiString())) {
            std::cerr << "Unable to load texture " + textureName.toAnsiString() << std::endl;
        }

        m_textures.push_back(tex);
    }
}

void Map::unload()
{
    for (int i = 0 ; i < m_textures.size() ; i++) {
        delete m_textures[i];
    }

    m_textures.clear();

    m_loaded = false;
}

void Map::draw(void)
{

    if (m_textures.size() > 0) {
        glEnable(GL_TEXTURE_2D);
        sf::Texture::bind(m_textures[0]->getTexture());

        for (float y = 0.0f ; y < 10.f ; y+=1.0f) {
            for (float x = 0.0f ; x < 10.f ; x+=1.0f) {
                glBegin(GL_QUADS);
                    glTexCoord2d(0,1); glVertex3f(x, 0.0f, y+1.0f);
                    glTexCoord2d(1,1); glVertex3f(x+1.0f, 0.0f, y+1.0f);
                    glTexCoord2d(1,0); glVertex3f(x+1.0f, 0.0f, y);
                    glTexCoord2d(0,0); glVertex3f(x, 0.0f, y);
                glEnd();
            }
        }
    }

    // Draw a dummy grid
    /*glMatrixMode(GL_MODELVIEW);
    for (float x = -10.0f ; x < 10.0f ; x+=1.0f) {
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex3f(x,0.0f,10.0f);
        glVertex3f(x,0.0f,-10.0f);
        glVertex3f(10.0f,-0.0f,x);
        glVertex3f(-10.0f,-0.0f,x);
        glEnd();
    }*/
}
