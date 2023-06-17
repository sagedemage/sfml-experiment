#include <iostream>

sf::Vector2f player_boundary(sf::Vector2f position)
{
    if (position.x+25 >= 500.f)
    {
        /* Right boundary */
        position.x = float(500 - 25);
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
    else if (position.y+25 >= 500)
    {
        /* Bottom boudnary */
        position.y = float(500 - 25);
    }
    return position;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "2D Game!");
    sf::RectangleShape player(sf::Vector2f(25, 25)); // radius
    sf::RectangleShape background(sf::Vector2f(500, 500));
    window.setFramerateLimit(60);
    sf::Color custom_background_color = sf::Color(84, 193, 255, 255);
    sf::Color custom_player_color = sf::Color(91, 31, 255, 255);
    player.setFillColor(custom_player_color);
    background.setFillColor(custom_background_color);

    const float speed = 2.f;

    sf::Music music;
    if (!music.openFromFile("assets/music/empty.ogg")) {
        return -1;
    }
    
    music.setLoop(true);
    music.play();

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
            player.move(-speed, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            // left key is pressed: move our character
            player.move(speed, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // left key is pressed: move our character
            player.move(0.f, -speed);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // left key is pressed: move our character
            player.move(0.f, speed);
        }

        // Player Boundary
        sf::Vector2f player_position = player_boundary(player.getPosition());
        player.setPosition(player_position);

        /*
        std::cout << "X" << std::endl;
        std::cout << circle_position.x << std::endl;
        std::cout << "Y" << std::endl;
        std::cout << circle_position.y << std::endl;
        */

        window.clear();
        window.draw(background);
        window.draw(player);
        window.display();
    }

    return 0;
}