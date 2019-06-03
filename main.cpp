#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

int main()
{

    RenderWindow window(VideoMode(640, 480), "Test game");

    Clock clock;

    Player cat ("cat.png",250, 250, 96.0, 96.0);

    float CurrentFrame = 0;

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;


        //eee
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
            cat.dir = 1;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            cat.dir = 0;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            cat.dir = 3;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 288, 96, 96));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
            cat.dir = 2;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96));
        }

        cat.update(time);
        window.clear();
        window.draw(cat.sprite);
        window.display();
    }

    return 0;
}