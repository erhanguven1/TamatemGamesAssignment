//
//  ParallaxScene.hpp
//  
//
//  Created by erhan güven on 23.12.2023.
//

#ifndef ParallaxScene_hpp
#define ParallaxScene_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "ParallaxLayer.hpp"
#include "../Character.hpp"

//ParallaxScene is a ParallaxNode abstraction

class ParallaxScene : public cocos2d::Node
{
public:
    ParallaxScene();
    void addToPositionX(float x);
    void onJumpButtonClick(Ref* sender);
    void onChangeGlassesButtonClick(Ref* sender);

private:
    cocos2d::ParallaxNode* m_parallaxNode;
    std::vector<ParallaxLayer*> m_layers;
    
    float m_leftLimit = -210;
    float m_rightLimit = 580;
    
    Character* m_character = nullptr;
    
    void registerListeners();
};

#endif /* ParallaxScene_hpp */
