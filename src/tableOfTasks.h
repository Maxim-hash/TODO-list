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
        status = 0;
        name = t_name;
        priority = t_priority;
        del_button.setRadius(11);
        complete_button.setRadius(11);
    }

    void setPosition( int y) {
        this->y += y;
    }

    void draw(RenderWindow& window) {
        del_button.setFillColor(Color(60, 60, 60));
        complete_button.setFillColor(Color(60, 60, 60));
        if(x == 30){
            complete_button.setPosition(x+(50* 17), y);
            del_button.setPosition(x+(50* 17) + 25, y);     
            window.draw(complete_button);
            window.draw(del_button);
        }
    }

    void set_color_del_but(RenderWindow& window) {
        del_button.setFillColor(Color::Red);
        window.draw(del_button);
    }

    void set_color_com_but(RenderWindow& window) {
        complete_button.setFillColor(Color::Green);
        window.draw(complete_button);
    }

    void draw_priority(RenderWindow&  window) {
        s_priority.setSize(sf::Vector2f(22, 22));
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
            break;
        }
        window.draw(s_priority);
    }

    unsigned int getX(){ 
        return this->x;
        }

    unsigned int getY(){ 
        return this->y;
        }

    char getStatus(){
        return status;
    }

    void setStatus(char st){
        status = st;
    }

    void setY(int y) {
        this->y = y;
    }

    void setX(int x) {
        this->x = x;
    }

    bool contains_del(sf::Vector2f point) const{
        return del_button.getGlobalBounds().contains(point);
    }

    bool contains_com(sf::Vector2f point) const{
        return complete_button.getGlobalBounds().contains(point);
    }

private:
    sf::CircleShape complete_button;
    sf::CircleShape del_button;
    sf::RectangleShape s_priority;
    unsigned int x = 30 , y = 30;
    char status;
    std::string name;
    int priority;
    sf::Texture cancel;

};

#endif