//
//  Stick.hpp
//  Pickin Sticks SFML
//
//  Created by Suliman Alsaid on 3/5/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#ifndef Stick_hpp
#define Stick_hpp

#include "Entity.hpp"

class Stick: public Entity {
public:
    void newLocation(int SCREEN_WIDTH, int SCREEN_HEIGHT);
};

#endif /* Stick_hpp */
