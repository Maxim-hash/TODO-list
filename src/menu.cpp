#include "createTask.h"
#include "tableOfTasks.h"
#include <vector>

using namespace sf;

void graphics()
{
    std::vector<TableOfTasks> tasks;
    int priority = 0;
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
                String s = form1(priority);
                tasks.push_back(TableOfTasks(s, priority));
                for(unsigned int i = 0; i < tasks.size(); i++) {
                    if(tasks[i].getStatus() == 0 && tasks[i].getX() != 1000) {
                        tasks[i].setPosition(30);
                    }
                    
                }
            } 
                
        }
        unsigned int k;
        unsigned int f;
        
        for(unsigned int i = 0; i < tasks.size(); i++) {
            bool click  = false;
            auto pos = sf::Mouse::getPosition(window);
            if (tasks[i].contains_del(sf::Vector2f(pos))){
                click = Mouse::isButtonPressed(Mouse::Left);
                if(click) {
                    if(tasks[i].getX() == 30) {
                        tasks[i].setStatus(1);
                        k = i;
                    }
                }
            } else if (tasks[i].contains_com(sf::Vector2f(pos))){
                click = Mouse::isButtonPressed(Mouse::Left);
                if(click) {
                    if(tasks[i].getX() == 30) {
                        tasks[i].setY(30);
                        tasks[i].setX(1000);
                        tasks[i].setStatus(2);
                        f = i;
                    }
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
            if(tasks[i].getStatus() == 0){
                txt.setString(tasks[i].getName());
                txt.setPosition(tasks[i].getX(), tasks[i].getY());
                if(tasks[i].getX() == 30)
                    tasks[i].draw(window);  
                tasks[i].draw_priority(window);
                window.draw(txt);
            } else if(tasks[i].getStatus() == 1){ 
                if(!Mouse::isButtonPressed(Mouse::Left)) {
                    auto iter = tasks.begin();
                    tasks.erase(iter + k);
                    for(unsigned int j = 0; j < k; j++)
                        if(tasks[j].getX() == 30)
                            tasks[j].setPosition(-30);
                        
                }
            } else if(tasks[i].getStatus() == 2) {
                if(!Mouse::isButtonPressed(Mouse::Left)) {
                        tasks[i].setStatus(0);
                        for(unsigned int m = 0; m < tasks.size(); m++) {
                            if(tasks[m].getX() == 1000) {
                                tasks[m].setPosition(30);
                            }
                        }
                        for(unsigned int j = 0; j < f; j++)
                            if(tasks[j].getX() == 30)
                                tasks[j].setPosition(-30);
                        
                }
            }            
        }
        window.display();

    }
}