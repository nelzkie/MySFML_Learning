//
//  TextureHolder.cpp
//  SFML_Book_game
//
//  Created by Bellchan on 6/29/14.
//  Copyright (c) 2014 Bellchan. All rights reserved.
//

#include "TextureHolder.h"
void TextureHolder::load(Textures::ID id, const std::string &filename){
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    texture->loadFromFile(filename);
    mTextureMap.insert(std::make_pair(id, std::move(texture)));
}

sf::Texture& TextureHolder::get(Textures::ID id){
    auto found = mTextureMap.find(id);
    return  *found->second; // access the pointer and dereference it
}