//
//  ForegroundLayer.cpp
//
//
//  Created by erhan güven on 23.12.2023.
//

#include "ForegroundLayer.hpp"


ForegroundLayer *ForegroundLayer::create(uint8_t layer)
{
    ForegroundLayer* fLayer = new ForegroundLayer(layer);
    
    auto audi = cocos2d::Sprite::create("Audi.png");
    audi->setScale(1.0f);
    audi->setPosition(cocos2d::Vec2(500, 40));
    fLayer->addChild(audi);
    
    auto tree = cocos2d::Sprite::create("Tree.png");
    tree->setScale(.05f);
    tree->setPosition(cocos2d::Vec2(0, 90));
    fLayer->addChild(tree);
    
    return fLayer;
}
