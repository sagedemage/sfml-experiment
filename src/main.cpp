//#include <iostream>

#define LEVEL_WIDTH 750
#define LEVEL_HEIGHT 500

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
    // window
    sf::RenderWindow window(sf::VideoMode(LEVEL_WIDTH, LEVEL_HEIGHT), "2D Game");
    window.setFramerateLimit(60);

    // player
    sf::RectangleShape player(sf::Vector2f(25, 25));
    player.setFillColor(sf::Color(91, 31, 255, 255));

    const float speed = 2.f;

    sf::Music music;
    if (!music.openFromFile("assets/music/empty.ogg")) {
        return -1;
    }

    const int volume = 50;
    music.setVolume(volume);
    
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

        // set background color of the window
        window.clear(sf::Color(84, 193, 255, 255));
        window.draw(player);
        window.display();
    }

    return 0;
}