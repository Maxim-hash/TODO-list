#ifndef TABLEOFTASKS_H
#define TABLEOFTASKS_H

#include <SFML/Graphics.hpp>

class TableOfTasks : public sf::Transformable
{
    public:
    TableOfTasks() {
        
    }
    std::string getName() {
        return name;
    }

    TableOfTasks(std::string t_name) {
        //status = t_status;
        name = t_name;
        //priority = t_priority;
    }
    void setPosition(int x, int y) {
        this->x = x;
        this->y += y;
        sf::Transformable::setPosition(x, y);
    }
    ~TableOfTasks() {
        status = false;

    }
    unsigned int getX(){ return x;}
    unsigned int getY(){ return y;}
private:
    unsigned int x = 0 , y = 0;
    bool status;
    std::string name;
    int priority;
    sf::Texture cancel;

};

#endif