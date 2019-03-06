//
//  Game.cpp
//  Pickin Sticks SFML
//
//  Created by Suliman Alsaid on 3/5/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#include "Game.hpp"
#include "ResourcePath.hpp"

Game::Game(): win(sf::VideoMode(640, 480), "Pickin Sticks"), clock(){
    
    win.setFramerateLimit(60);
    
    if(!texStick.loadFromFile(resourcePath() + "stick.png")) {
        return -1;
    }
    texPlayer.loadFromFile(resourcePath() + "player.png");
    texGrass.loadFromFile(resourcePath() + "grass.png");
    times.loadFromFile(resourcePath() + "times.ttf");
    
    player.setTexture(texPlayer);
    player.setPosition(0, 0);
    stick.setTexture(texStick);
    stick.newLocation(640, 480);
    
    texGrass.setRepeated(true);
    
    sf::IntRect r;
    r.width = 640;
    r.height = 480;
    
    grass.setTextureRect(r);
    grass.setTexture(texGrass);
    grass.setPosition(0, 0);
    
    score.setFont(times);
    score.setCharacterSize(25);
    score.setString("Score: 0");
    score.setFillColor(sf::Color::Black);
    score.setPosition((640- score.getLocalBounds().width)/2, 0);
    
    
    
    moveUp = moveDown = moveLeft = moveRight = false;
    
    sound.loadFromFile(resourcePath() + "pickup.wav");
    collect.setBuffer(sound);
    
    moveAuto = false;
    
    

}


void Game::run() {
    
    while(win.isOpen()) {
        input();
        update();
        draw();
        
    }
}

void Game::input() {
    sf::Event e;
    while(win.pollEvent(e)) {
        if(e.type == sf::Event::Closed) {
            win.close();
        }
        
        if(e.type == sf::Event::KeyPressed) {
            switch (e.key.code) {
                case sf::Keyboard::Up:
                    if(!moveUp && player.getPosition().y > 0) {
                        moveUp = true;
                        player.move(Player::Up);
                    }
                    break;
                case sf::Keyboard::Down:
                    if(!moveDown && player.getPosition().y < 480 - 32) {
                        moveDown = true;
                        player.move(Player::Down);
                    }
                    break;
                case sf::Keyboard::Left:
                    if(!moveLeft && player.getPosition().x > 0) {
                        moveLeft = true;
                        player.move(Player::Left);
                    }
                    break;
                case sf::Keyboard::Right:
                    if(!moveRight && player.getPosition().x < 640 - 32) {
                        moveRight = true;
                        player.move(Player::Right);
                    }
                    break;
                    
                default:
                    break;
            }
        }
        
        if(e.type == sf::Event::KeyReleased) {
            switch (e.key.code) {
                case sf::Keyboard::Up:
                    moveUp = false;
                    break;
                case sf::Keyboard::Down:
                    moveDown = false;
                    break;
                case sf::Keyboard::Left:
                    moveLeft = false;
                    break;
                case sf::Keyboard::Right:
                    moveRight = false;
                    break;
                case sf::Keyboard::Enter:
                    moveAuto = !moveAuto;
                    clock.restart();
                    break;
                    
                default:
                    break;
            }
        }
        
        
        
    }
}

void Game::update() {
    if(player.collision(stick)) {
        
            stick.newLocation(640, 480);
        
        collect.play();
        player.increaseScore();
        score.setString("Score: " + std::to_string(player.getScore()));
    }
    
    if(moveAuto) {
        automove();
    }
    
}

void Game::draw() {
    win.clear();
    win.draw(grass);
    win.draw(stick);
    win.draw(player);
    win.draw(score);
    win.draw(highscoreText);
    win.display();
    
    
}

void Game::automove() {
    if(clock.getElapsedTime().asMilliseconds() >= 100s) {
        sf::Vector2f vec = stick.getPosition() - player.getPosition();
        if(vec.x > 0) {
            player.move(Player::Right);
        } else if(vec.x < 0){
            player.move(Player::Left);
        } else if(vec.y < 0 ){
            player.move(Player::Up);
        }
        else if(vec.y > 0 ){
            player.move(Player::Down);
        }
        
        clock.restart();
    }
}


