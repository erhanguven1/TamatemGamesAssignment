//
//  MidLayer.cpp
//  
//
//  Created by erhan güven on 23.12.2023.
//

#include "MidLayer.hpp"


MidLayer *MidLayer::create(uint8_t layer, Character*& character)
{
    MidLayer* midLayer = new MidLayer(layer);
    
    auto* characterParent = Node::create();
    midLayer->addChild(characterParent);
    
    //Create character with a base girl image
    character = Character::create("Girl.png", cocos2d::Vec2(0,0));
    //Wear sunglasses by default
    character->addAccessory("Sunglasses.png", AccessoryType::GLASSES);
    characterParent->addChild(character);
    
    return midLayer;
}
