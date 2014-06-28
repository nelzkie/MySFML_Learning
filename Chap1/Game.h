//
//  Game.h
//  SFML_Book_game
//
//  Created by Bellchan on 6/29/14.
//  Copyright (c) 2014 Bellchan. All rights reserved.
//

#ifndef __SFML_Book_game__Game__
#define __SFML_Book_game__Game__

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
class Game{
public:
    Game();
    void run();
    void handlePlayerInput(sf::Keyboard::Key,bool);
    
public:
    bool mIsMovingUp, mIsMovinDown, mIsMovingLeft, mIsMovingRight;
    
    
private:
    void processEvents();
    void update(sf::Time);
    void render();
    sf::RenderWindow mWindow;
    sf::Sprite mPlayer;
    sf::Texture mTexture;
};
#endif /* defined(__SFML_Book_game__Game__) */
