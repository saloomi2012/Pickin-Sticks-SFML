//
//  Player.hpp
//  Pickin Sticks SFML
//
//  Created by Suliman Alsaid on 3/5/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Entity.hpp"



class Player: public Entity {
    
public:
    Player();
    Player(sf::Texture& tex);
    void increaseScore();
    int getScore();
    
    
private:
    
    int score;
    
};

#endif /* Player_hpp */
