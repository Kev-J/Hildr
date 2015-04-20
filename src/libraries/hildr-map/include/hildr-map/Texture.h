#ifndef TEXTURE_H
#define TEXTURE_H

#include <SFML/Graphics.hpp>

class Texture {
    public:
        bool load(sf::String name, sf::String textureFileName);
        void unload(void);
        sf::Texture *getTexture(void);
    private:
	sf::Texture *m_texture;

        sf::String m_name;
};

#endif
