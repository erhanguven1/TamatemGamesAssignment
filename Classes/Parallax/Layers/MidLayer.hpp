//
//  MidLayer.hpp
//  
//
//  Created by erhan güven on 23.12.2023.
//

#ifndef MidLayer_hpp
#define MidLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "../ParallaxLayer.hpp"
#include "../../Character.hpp"

class MidLayer : public ParallaxLayer
{
public:
    static MidLayer* create(uint8_t layer, Character*& character);
private:
    MidLayer(uint8_t layer) : ParallaxLayer(layer){}
};

#endif /* MidLayer_hpp */
