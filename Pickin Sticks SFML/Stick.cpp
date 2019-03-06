//
//  Stick.cpp
//  Pickin Sticks SFML
//
//  Created by Suliman Alsaid on 3/5/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#include "Stick.hpp"
#include <ctime>
#include <cstdlib>

void Stick::newLocation(int SCREEN_WIDTH, int SCREEN_HEIGHT) {
    int rows =  SCREEN_HEIGHT / 32;
    int columns = SCREEN_WIDTH / 32;
    
    srand(time(0));
    
    int x = (rand() % (columns)) * 32;
    int y = (rand() % rows) * 32;
    
    sf::Vector2f vec(x, y);
    this->setPosition(vec);
    
}
