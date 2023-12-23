//
//  BackgroundLayer.cpp
//  
//
//  Created by erhan güven on 23.12.2023.
//

#include "BackgroundLayer.hpp"


BackgroundLayer *BackgroundLayer::create(uint8_t layer)
{
    BackgroundLayer* bLayer = new BackgroundLayer(layer);
    
    auto cityBackground = cocos2d::Sprite::create("CityBackground.jpeg");
    bLayer->addChild(cityBackground);
    
    return bLayer;
}
