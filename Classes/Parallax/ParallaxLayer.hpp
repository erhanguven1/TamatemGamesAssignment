//
//  ParallaxLayer.hpp
//  
//
//  Created by erhan güven on 23.12.2023.
//

#ifndef ParallaxLayer_hpp
#define ParallaxLayer_hpp

#include <stdio.h>
#include <cocos2d.h>

class ParallaxLayer : public cocos2d::Node
{
public:
    ParallaxLayer(uint8_t layer) : m_layer(layer) {}
    inline uint8_t getLayer(){ return m_layer; }
private:
    uint8_t m_layer;
};

#endif /* ParallaxLayer_hpp */
