#include <SFML/Graphics.hpp>
#include "Player.h"
#include "map.h"
#include "view.h"

using namespace sf;

int main()
{

    RenderWindow window(VideoMode(640, 480), "Test game");

    Clock clock;

    Player cat ("cat.png",250, 250, 96.0, 96.0);

    float CurrentFrame = 0;

    Image map_image;
    map_image.loadFromFile("image//map.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);

    view.reset(FloatRect(0, 0, 640, 480));

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;


        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if ((Keyboard::isKeyPressed(Keyboard::Left))) {
            cat.dir = 1;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96));
            getCoordForView(cat.getpPlayerCoordinateX(), cat.getpPlayerCoordinateY());
        }

        if ((Keyboard::isKeyPressed(Keyboard::Right))) {
            cat.dir = 0;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96));
            getCoordForView(cat.getpPlayerCoordinateX(), cat.getpPlayerCoordinateY());
        }

        if ((Keyboard::isKeyPressed(Keyboard::Up))) {
            cat.dir = 3;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 288, 96, 96));
            getCoordForView(cat.getpPlayerCoordinateX(), cat.getpPlayerCoordinateY());
        }

        if ((Keyboard::isKeyPressed(Keyboard::Down))) {
            cat.dir = 2;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96));
            getCoordForView(cat.getpPlayerCoordinateX(), cat.getpPlayerCoordinateY());
        }

        cat.update(time);
        window.clear();

        for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++){

            if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
            if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
            if (TileMap[i][j] == '0')  s_map.setTextureRect(IntRect(64, 0, 32, 32));

            s_map.setPosition(j * 32, i * 32);

            window.draw(s_map);

            }

        window.setView(view);
        window.draw(cat.sprite);
        window.display();
    }

    return 0;
}