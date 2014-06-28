//
//  TextureHolder.h
//  SFML_Book_game
//
//  Created by Bellchan on 6/29/14.
//  Copyright (c) 2014 Bellchan. All rights reserved.
//

#ifndef __SFML_Book_game__TextureHolder__
#define __SFML_Book_game__TextureHolder__

#include <iostream>


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace Textures {
    enum ID{Landscape,Airplane,Missile};
    
}
class TextureHolder{
    
    
    
public:
    std::map<Textures::ID,std::unique_ptr<sf::Texture>> mTextureMap;
    void load(Textures::ID id, const std::string  &filename);
    sf::Texture &get(Textures::ID id);

    const sf::Texture &get(Textures::ID id) const;
};
#endif /* defined(__SFML_Book_game__TextureHolder__) */
