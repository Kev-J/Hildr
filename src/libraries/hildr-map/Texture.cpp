#include "Texture.h"

bool Texture::load(sf::String name, sf::String textureFileName)
{
    m_texture = new sf::Texture();
    if (!m_texture->loadFromFile(textureFileName)) {
        return false;
    }

    m_name = name;

    return true;
}

void Texture::unload()
{
    delete m_texture;
}

sf::Texture* Texture::getTexture(void)
{
    return m_texture;
}
