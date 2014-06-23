

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
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
    void update();
    void render();
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
    
    
};

Game::Game() : mWindow(sf::VideoMode(640,480),"SFML Applicaton"),mPlayer(){

    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.0f, 100.0f);
    mPlayer.setFillColor(sf::Color::Cyan);
    
}
void Game::run(){
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
        
    }
}

void Game::processEvents(){
    sf::Event event;
    while(mWindow.pollEvent(event)){
        if(event.type == sf::Event::Closed){
       
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

void Game::update(){
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
    
    mPlayer.move(movement);
}

void Game::render(){
    mWindow.clear();
    mWindow.draw(mPlayer);
    
    mWindow.display();
}


int main(int, char const**)
{
    Game game;
    game.run();
   
    
    
    return EXIT_SUCCESS;
}
