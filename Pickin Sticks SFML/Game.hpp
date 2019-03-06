//
//  Game.hpp
//  Pickin Sticks SFML
//
//  Created by Suliman Alsaid on 3/5/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "Stick.hpp"
#include "Player.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

class Game {
public:
    Game();
    void run();
    void update();
    void input();
    void draw();
    void automove();
    
    
private:
    Player player;
    Stick stick;
    sf::Sprite grass;
    sf::Texture texPlayer;
    sf::Texture texStick;
    sf::Texture texGrass;
    sf::Font times;
    sf::Text highscoreText;
    sf::Text score;
    sf::RenderWindow win;
    sf::SoundBuffer sound;
    sf::Sound collect;
    sf::Clock clock;
    bool moveLeft;
    bool moveRight;
    bool moveUp;
    bool moveDown;
    bool moveAuto;
    

    
    
};

#endif /* Game_hpp */
