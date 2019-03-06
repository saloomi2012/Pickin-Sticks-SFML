//
//  Entity.hpp
//  Pickin Sticks SFML
//
//  Created by Suliman Alsaid on 3/5/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <SFML/Graphics.hpp>

class Entity: public sf::Sprite {
    
public:
    Entity();
    Entity(sf::Texture& tex);
    bool collision(Entity e);
    enum Movement {
        Up, Down, Left, Right
    };
    
    void move(Movement m);
    
    
};

#endif /* Entity_hpp */
