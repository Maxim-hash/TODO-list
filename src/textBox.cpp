#include <SFML/Graphics.hpp>

 
bool verify()
{
    sf::RenderWindow app(sf::VideoMode(200, 100), L"SFML window");
    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                app.close();
                return 1;
                
        }
        }
        app.clear();
        app.display();
    }
    return 1;
 
}