#include "createTask.h"
#include "tableOfTasks.h"
#include <vector>

using namespace sf;

void graphics()
{
    std::vector<TableOfTasks> tasks;
    RenderWindow window(VideoMode(1920, 1080), "TODO-List", Style::Default);
    window.clear(Color(50, 50, 50));
    Font font ;
    font.loadFromFile("FreeMono.ttf");
    Text txt ;
    txt.setPosition ( 50 , 50 ) ;
    txt.setFont ( font ) ;
    txt.setCharacterSize(22);

    Texture menuTexture1, menuTexture2, menuTexture3;
	menuTexture1.loadFromFile("images/new_task_button.png");
    menuTexture2.loadFromFile("images/calendar_button.png");
	Sprite menu1(menuTexture1);
    Sprite menu2(menuTexture2);
	menu1.setPosition(0, 15);
    menu2.setPosition(200, 15);

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

        menu1.setColor(Color::White);
        menu2.setColor(Color::White);

        if (IntRect(0, 15, 150, 27).contains(Mouse::getPosition(window))) {
            menu1.setColor(Color(50, 50, 50));
            if (Mouse::isButtonPressed(Mouse::Left)) {
                String s = form1();
                tasks.push_back(TableOfTasks(s));
                for(unsigned int i = 0; i < tasks.size(); i++) {
                    tasks[i].setPosition(30, 30);
                } 
                
            }
        }
        if (IntRect(200, 15, 100, 27).contains(Mouse::getPosition(window))) {
            menu2.setColor(Color(50, 50, 50)); 
            if (Mouse::isButtonPressed(Mouse::Left)) {
                form2();
            }
        }
        window.clear(Color(50, 50, 50));
        window.draw(menu1);
        window.draw(menu2);
        for(unsigned int i = 0; i < tasks.size(); i++) {
            txt.setString(tasks[i].getName());
            txt.setPosition(tasks[i].getX(), tasks[i].getY());
            window.draw(txt);
        }
        
        window.display();

    }
}