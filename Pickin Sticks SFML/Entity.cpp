//
//  Entity.cpp
//  Pickin Sticks SFML
//
//  Created by Suliman Alsaid on 3/5/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(){}

Entity::Entity(sf::Texture& tex) : sf::Sprite(tex) {}

bool Entity::collision(Entity e) {
    if(this->getPosition() == e.getPosition())
        return true;
    
    return false;
    
}

void Entity::move(Movement m){
    switch (m) {
        case Entity::Up:
            this->sf::Transformable::move(0, -32);
            break;
        case Entity::Down:
            this->sf::Transformable::move(0, 32);
            break;
        case Entity::Left:
            this->sf::Transformable::move(-32, 0);
            break;
        case Entity::Right:
            this->sf::Transformable::move(32, 0);
            break;
        default:
            break;
    }
}
