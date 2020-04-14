#include "createTask.h"
#include "textBox.h"
#include <string>

using namespace sf;

class TextField : public Transformable{
public:
    TextField(unsigned int maxChars) :
    m_size(maxChars),
    m_rect(sf::Vector2f(15 * m_size, 20)),
    m_hasfocus(false)
    {
        m_font.loadFromFile("FreeMono.ttf");
        m_rect.setOutlineThickness(2);
        m_rect.setFillColor(sf::Color::White);
        m_rect.setOutlineColor(sf::Color(127,127,127));
        m_rect.setPosition(this->getPosition());
    }
    String getText() {
        return m_text;
    }
    void setPosition(float x, float y){
        sf::Transformable::setPosition(x, y);
        m_rect.setPosition(x, y);
    }
    bool contains(sf::Vector2f point) const{
        return m_rect.getGlobalBounds().contains(point);
    }
    void setFocus(bool focus){
        m_hasfocus = focus;
        if (focus){
            m_rect.setOutlineColor(sf::Color::Blue);
        }else{
            m_rect.setOutlineColor(sf::Color(127, 127, 127)); // Gray color
        }
    }
    void handleInput(sf::Event e){
        if (!m_hasfocus || e.type != sf::Event::TextEntered)
            return;

        if (e.text.unicode == 8){   // Delete key
            m_text = m_text.substr(0, m_text.size() - 1);
        }else if (m_text.size() < m_size){
            m_text += e.text.unicode;
        }
    }
    virtual void draw(RenderWindow& window) const {
        Text txt;
        txt.setFont(m_font);
        txt.setPosition(0, 0);
        txt.setCharacterSize(20);
        txt.setFillColor(Color::Black);
        txt.setString(m_text);
        window.draw(txt);
}

private:

    unsigned int m_size;
    sf::Font m_font;
    std::string m_text;
    sf::RectangleShape m_rect;
    bool m_hasfocus;
};

std::string form1() 
{
    t:  
    Texture minor_priority_button, normal_priority_button, major_priority_button;
    minor_priority_button.loadFromFile("images/priority_button.png");
    normal_priority_button.loadFromFile("images/priority_button.png");
    major_priority_button.loadFromFile("images/priority_button.png");
    Sprite b1(minor_priority_button);
    Sprite b2(normal_priority_button);
    Sprite b3(major_priority_button);
    b1.setPosition(10, 50);
    b2.setPosition(60, 50);
    b3.setPosition(110, 50);
    RectangleShape m_rect;
    m_rect.setSize(sf::Vector2f(15 * 50, 20));
    m_rect.setOutlineThickness(2);
    m_rect.setFillColor(sf::Color::White);
    m_rect.setOutlineColor(sf::Color(127,127,127));
    RenderWindow window({ 750, 250 }, "New Task", Style::Close);

    TextField tf(50);
    tf.setPosition(0, 0);

    while (window.isOpen())
    {
        b1.setColor(Color::White);
        b2.setColor(Color::White);
        b3.setColor(Color::White);

        if(IntRect(10, 50, 50, 33).contains(Mouse::getPosition(window))) 
            b1.setColor(Color::Green);

        if(IntRect(60, 50, 50, 33).contains(Mouse::getPosition(window))) {
            b1.setColor(Color::Green);
            b2.setColor(Color::Yellow);
        }
        if(IntRect(110, 50, 50, 33).contains(Mouse::getPosition(window))) {
            b1.setColor(Color::Green);
            b2.setColor(Color::Yellow);
            b3.setColor(Color::Red);
        }
        for (Event event; window.pollEvent(event);)
            if (event.type == Event::Closed)
                window.close();
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                int vf = verify();
                if(vf){
                    if(tf.getText() != "") {
                        return tf.getText();
                        window.close();
                    }else goto t;
        
                }
            }else if (event.type == Event::MouseButtonReleased){
                auto pos = sf::Mouse::getPosition(window);
                tf.setFocus(false);
                if (tf.contains(sf::Vector2f(pos))){
                    tf.setFocus(true);
                }
            }else{
                tf.handleInput(event);
            }
        window.clear();
        window.draw(b1);
        window.draw(b2);
        window.draw(b3);
        window.draw(m_rect);
        tf.draw(window);
        window.display();
        }
    return "";
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