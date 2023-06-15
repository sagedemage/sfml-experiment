#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "2D Game!");
    sf::CircleShape circle(25.f);
    sf::Vector2f size = sf::Vector2f(500, 500);
    sf::RectangleShape background(size);
    //window.set
    //sf::
    circle.setFillColor(sf::Color::Green);
    background.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(circle);
        window.display();
    }

    return 0;
}