#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player{

private:
    float x, y;

public:
    float w, h, dx, dy, speed ;
    int dir ;
    string file;
//    String File;
    Image image;
    Texture texture;
    Sprite sprite;

    Player(string f, float X, float Y, float weight, float high){

        file = f;
        w = weight; h = high;
        image.loadFromFile("image//" + file);
        image.createMaskFromColor(Color(41, 33, 59));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        x = X; y = Y;
        sprite.setTextureRect(IntRect(0, 0, w, h));
    }

    void update(float time)
    {
        switch (dir)
        {
            case 0: dx = speed; dy = 0; break;
            case 1: dx = -speed; dy = 0; break;
            case 2: dx = 0; dy = speed; break;
            case 3: dx = 0; dy = -speed; break;
        }

        x += dx*time;
        y += dy*time;

        speed = 0;
        sprite.setPosition(x,y);
    }

    float getpPlayerCoordinateX(){

        return x;
    }

    float getpPlayerCoordinateY(){
        return y;
    }
};
