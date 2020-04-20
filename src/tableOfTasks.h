#ifndef TABLEOFTASKS_H
#define TABLEOFTASKS_H

#include <SFML/Graphics.hpp>

using namespace sf;

class TableOfTasks : public Transformable
{
    public:
    TableOfTasks() {
        
    }

    std::string getName() {
        return name;
    }

    TableOfTasks(std::string t_name, int t_priority) {
        status = true;
        name = t_name;
        priority = t_priority;
    }

    void setPosition(int x, int y) {
        this->x = x;
        this->y += y;
    }

    void draw(RenderWindow& window) {
        s_priority.setSize(sf::Vector2f(22, 22));
        del_button.setSize(sf::Vector2f(22, 22));
        del_button.setPosition(x+(name.length()* 17), y);
        del_button.setFillColor(Color::Red);
        s_priority.setPosition(x - 25, y);
        switch (priority)
        {
        case 0:
            s_priority.setFillColor(sf::Color::Green);
            break;
        case 1:
            s_priority.setFillColor(sf::Color::Yellow);
            break;
        case 2:
            s_priority.setFillColor(sf::Color::Red);
        }
        window.draw(del_button);
        window.draw(s_priority);
    }

    unsigned int getX(){ 
        return this->x;
        }

    unsigned int getY(){ 
        return this->y;
        }

    bool getStatus(){
        return status;
    }

    void setStatus(bool st){
        status = st;
    }

    bool contains(sf::Vector2f point) const{
        return del_button.getGlobalBounds().contains(point);
    }

private:
    sf::RectangleShape del_button;
    sf::RectangleShape s_priority;
    unsigned int x = 30 , y = 30;
    bool status;
    std::string name;
    int priority;
    sf::Texture cancel;

};

#endif