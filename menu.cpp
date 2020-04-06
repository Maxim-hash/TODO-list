#include <SFML/Graphics.hpp>

using namespace sf;

void graphics()
{
    RenderWindow window(VideoMode(1920, 1080), "TODO-List", Style::Fullscreen);
    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed) {
                window.close();
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        window.display();

    }
}