#include <SFML/Graphics.hpp>
#include <iostream>

sf::Vector2f player_boundary(sf::Vector2f position)
{
    if (position.x + 50.f >= 500.f)
    {
        /* Right boundary */
        position.x = float(500 - 50);
    }
    else if (position.x <= 0.f)
    {
        /* Left  boundary */
        position.x = 0.f;
    }
    if (position.y <= 0.f)
    {
        /* Top boudnary */
        position.y = 0.f;
    }
    else if (position.y + 50.f >= 500)
    {
        /* Bottom boudnary */
        position.y = float(500 - 50);
    }
    return position;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "2D Game!");
    sf::CircleShape circle(25.f); // radius
    sf::RectangleShape background(sf::Vector2f(500, 500));
    window.setFramerateLimit(60);
    circle.setFillColor(sf::Color::Green);
    background.setFillColor(sf::Color::Blue);

    const float speed = 2.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }

        // Keybindings
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            // left key is pressed: move our character
            circle.move(-speed, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            // left key is pressed: move our character
            circle.move(speed, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // left key is pressed: move our character
            circle.move(0.f, -speed);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // left key is pressed: move our character
            circle.move(0.f, speed);
        }

        sf::Vector2f circle_position = circle.getPosition();

        // Player Boundary
        circle_position = player_boundary(circle_position);

        circle.setPosition(circle_position);

        /*
        std::cout << "X" << std::endl;
        std::cout << circle_position.x << std::endl;
        std::cout << "Y" << std::endl;
        std::cout << circle_position.y << std::endl;
        */

        window.clear();
        window.draw(background);
        window.draw(circle);
        window.display();
    }

    return 0;
}