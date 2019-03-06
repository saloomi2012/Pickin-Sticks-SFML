//
//  Player.cpp
//  Pickin Sticks SFML
//
//  Created by Suliman Alsaid on 3/5/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#include "Player.hpp"
Player::Player(){
    this->score = 0;
}

Player::Player(sf::Texture& tex): Entity(tex){
    this->score = 0;
}

void Player::increaseScore() {
    score++;
}

int Player::getScore() {
    return score;
}
