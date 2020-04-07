#include <SFML/Graphics.hpp>

using namespace sf;

void form1() 
{
    RenderWindow window(VideoMode(400, 300), "New task");
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

void form2()
{
    RenderWindow window(VideoMode(1920, 1080), "Calendar", Style::Default);
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