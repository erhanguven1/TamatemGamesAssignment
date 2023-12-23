//
//  ForegroundLayer.hpp
//  
//
//  Created by erhan güven on 23.12.2023.
//

#ifndef ForegroundLayer_hpp
#define ForegroundLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "../ParallaxLayer.hpp"

class ForegroundLayer : public ParallaxLayer
{
public:
    static ForegroundLayer* create(uint8_t layer);
private:
    ForegroundLayer(uint8_t layer) : ParallaxLayer(layer){}
};

#endif /* ForegroundLayer */
