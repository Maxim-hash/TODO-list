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
}
else{
m_rect.setOutlineColor(sf::Color(127, 127, 127)); // Gray color
}
}
void handleInput(sf::Event e){
if (!m_hasfocus || e.type != sf::Event::TextEntered)
return;

if (e.text.unicode == 8){   // Delete key
m_text = m_text.substr(0, m_text.size() - 1);
}
else if (m_text.size() < m_size){
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
    RectangleShape m_rect;
    m_rect.setSize(sf::Vector2f(15 * 50, 20));
    m_rect.setOutlineThickness(2);
    m_rect.setFillColor(sf::Color::White);
    m_rect.setOutlineColor(sf::Color(127,127,127));
    RenderWindow window({ 750, 500 }, "New Task", Style::Close);

TextField tf(50);
tf.setPosition(0, 0);

while (window.isOpen())
{
for (Event event; window.pollEvent(event);)
if (event.type == Event::Closed)
window.close();
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
    int vf = verify();
    if(vf){
        return tf.getText();
        window.close();
    }
}
else if (event.type == Event::MouseButtonReleased){
auto pos = sf::Mouse::getPosition(window);
tf.setFocus(false);
if (tf.contains(sf::Vector2f(pos))){
tf.setFocus(true);
}
}
else{
tf.handleInput(event);
}
window.clear();
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