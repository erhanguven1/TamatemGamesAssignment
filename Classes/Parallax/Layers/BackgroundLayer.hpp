//
//  BackgroundLayer.hpp
//  
//
//  Created by erhan güven on 23.12.2023.
//

#ifndef BackgroundLayer_hpp
#define BackgroundLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "../ParallaxLayer.hpp"

class BackgroundLayer : public ParallaxLayer
{
public:
    static BackgroundLayer* create(uint8_t layer);
private:
    BackgroundLayer(uint8_t layer) : ParallaxLayer(layer){}
};

#endif /* BackgroundLayer_hpp */
