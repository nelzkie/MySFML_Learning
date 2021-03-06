//
//  Game.cpp
//  SFML_Book_game
//
//  Created by Bellchan on 6/29/14.
//  Copyright (c) 2014 Bellchan. All rights reserved.
//

#include "Game.h"
#include "TextureHolder.h"
Game::Game() : mWindow(sf::VideoMode(640,480),"SFML Applicaton"),mPlayer(){
    TextureHolder textures;
    textures.load(Textures::Airplane, resourcePath() + "icon.png");
    
    if(!mTexture.loadFromFile( resourcePath() + "cute_image.jpg")){
        std::cout<<"haha"<<std::endl;
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);
    
    std::cout<<sf::Texture::getMaximumSize() << std::endl;
    
}
void Game::run(){
    sf::Clock clock;
    while (mWindow.isOpen()) {
        
        // this lets the clock return the elapsed time since its start and restars the clock from zero
        sf::Time deltaTime = clock.restart();
        
        processEvents();
        update(deltaTime);
        render();
        
    }
}

void Game::processEvents(){
    sf::Event event;
    while(mWindow.pollEvent(event)){
        
        
        switch (event.type) {
                // if key pressed
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code,true);
                
                break;
                
                // if release
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code,false);
                break;
                
                // if closed
            case sf::Event::Closed:
                
                mWindow.close();
                break;
                
            default:
                break;
        }
        
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    
    if(key == sf::Keyboard::W){
        mIsMovingUp = isPressed;
    }else if(key == sf::Keyboard::S){
        mIsMovinDown = isPressed;
        
    }else if(key ==sf::Keyboard::A) {
        mIsMovingLeft = isPressed;
    }else if(key == sf::Keyboard::D){
        mIsMovingRight = isPressed;
    }
}

void Game::update(sf::Time deltaTime){
    sf::Vector2f movement(0.f,0.f);
    if(mIsMovingUp){
        movement.y -= 1.f;
        
    }
    if(mIsMovinDown){
        movement.y += 1.f;
    }
    if(mIsMovingLeft){
        movement.x -= 1.f;
    }
    if(mIsMovingRight){
        movement.x += 1.f;
    }
    sf::err();
    
    
    
    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render(){
    mWindow.clear();
    mWindow.draw(mPlayer);
    
    mWindow.display();
}
