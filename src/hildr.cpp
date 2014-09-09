#include <SFML/Graphics.hpp>

int main(int argc, char **argv)
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Hildr");
    
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                // The window requested to be closed
                window.close();
            }
        }
    }
    return 0;
}
