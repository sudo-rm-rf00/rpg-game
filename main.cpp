#include <SFML/Graphics.hpp>

int main()
{
    //-------------------INITIALIZE----------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);
    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100, 100));

    sf::RectangleShape rectangle(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(sf::Vector2f(400, 300));
    rectangle.setOrigin(rectangle.getSize() / 2.f);
    rectangle.setRotation(45.f);

    sf::CircleShape triangle(80.f, 3);
    triangle.setFillColor(sf::Color::Yellow);
    triangle.setPosition(sf::Vector2f(250, 250));
    triangle.setRotation(25.f);

    sf::CircleShape pentagon(80.f, 5);
    pentagon.setFillColor(sf::Color::Cyan);
    pentagon.setPosition(sf::Vector2f(450, 450));
    //-------------------INITIALIZE----------------

    // main game loop
    while (window.isOpen())
    {
        //-------------------UPDATE----------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //-------------------UPDATE----------------


        //-------------------DRAW----------------
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(rectangle);
        window.draw(triangle);
        window.draw(pentagon);
        window.display();
        //-------------------DRAW----------------
    }
    return 0;
}