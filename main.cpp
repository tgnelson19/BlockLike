#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,800), "BlockLike");

    window.setFramerateLimit(60);

    sf::RectangleShape blockGuy(sf::Vector2f(20,20));
    blockGuy.setPosition(400,400);
    blockGuy.setFillColor(sf::Color::Red);

    sf::RectangleShape blockGirl(sf::Vector2f(20,20));
    blockGirl.setPosition(400,400);
    blockGirl.setFillColor(sf::Color::Blue);

    bool BisMoving; int Bdx; int Bdy;
    bool GisMoving; int Gdx; int Gdy;

    float gravity = 3;

    int speed = 9;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){if (event.type == sf::Event::Closed) window.close();}

        BisMoving = false; Bdx = 0; Bdy = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { BisMoving = true; Bdx = 1;}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { BisMoving = true; Bdx = -1;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { BisMoving = true; Bdy = 1;}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { BisMoving = true; Bdy = -1;}

        GisMoving = false; Gdx = 0; Gdy = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { GisMoving = true; Gdx = 1;}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { GisMoving = true; Gdx = -1;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { GisMoving = true; Gdy = 1;}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { GisMoving = true; Gdy = -1;}

        if (blockGuy.getPosition().y < 780){
            blockGuy.setPosition(blockGuy.getPosition().x, blockGuy.getPosition().y + gravity);
        }

        if (blockGirl.getPosition().y < 780){
            blockGirl.setPosition(blockGirl.getPosition().x, blockGirl.getPosition().y + gravity);
        }


        blockGuy.setPosition(blockGuy.getPosition().x + (Bdx * speed), blockGuy.getPosition().y - (Bdy * speed));

        blockGirl.setPosition(blockGirl.getPosition().x + (Gdx * speed), blockGirl.getPosition().y - (Gdy * speed));



        window.clear();
        window.draw(blockGuy);
        window.draw(blockGirl);
        window.display();
    }

    return 0;
}