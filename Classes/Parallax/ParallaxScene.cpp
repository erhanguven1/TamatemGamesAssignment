//
//  ParallaxScene.cpp
//  
//
//  Created by erhan güven on 23.12.2023.
//

#include "ParallaxScene.hpp"
#include "Layers/BackgroundLayer.hpp"
#include "Layers/MidLayer.hpp"
#include "Layers/ForegroundLayer.hpp"

using namespace cocos2d;

//Construct the ParallaxScene with three layers
ParallaxScene::ParallaxScene()
{
    //Create the background layer, city background
    auto* bgLayer = BackgroundLayer::create(0);
    //Create the mid layer, character
    //Filling the pointer 'm_character' inside of the create method
    auto* midLayer = MidLayer::create(1, m_character);
    //Create the foreground layer, a car and a tree
    auto* fgLayer = ForegroundLayer::create(2);
    
    //Create the parallaxNode itself
    m_parallaxNode = cocos2d::ParallaxNode::create();
    
    //Add layers using the information from the layers created above
    
    m_parallaxNode->addChild(bgLayer, bgLayer->getLayer(), cocos2d::Vec2(0.35f, 0.35f), cocos2d::Vec2(175, 125));
    m_parallaxNode->addChild(midLayer, midLayer->getLayer(), cocos2d::Vec2(0.35f, 0.35f), cocos2d::Vec2(250, 90));
    m_parallaxNode->addChild(fgLayer, fgLayer->getLayer(), cocos2d::Vec2(1.0f, 1.0f), cocos2d::Vec2(0, 0));
    
    this->addChild(m_parallaxNode);
    registerListeners();
}

//Set x position of the parallaxNode using touch delta
void ParallaxScene::addToPositionX(float x)
{
    m_parallaxNode->setPositionX(m_parallaxNode->getPositionX() + x);
}

//Register touch listeners
void ParallaxScene::registerListeners()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = [&](Touch* touch, Event* event){return true;};
    
    //Register touch move listener
    touchListener->onTouchMoved = [&](Touch* touch, Event* event)
    {
        float delta = touch->getDelta().x;
        float newPos = m_parallaxNode->getPositionX() + delta;
        
        //Check if new potential position exceeds limits, if not, then change parallax position's x value
        if(newPos < m_rightLimit && newPos > m_leftLimit)
        {
            addToPositionX(delta);
        }
    };
    
    touchListener->onTouchEnded = [&](Touch* touch, Event* event){};
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void ParallaxScene::onJumpButtonClick(cocos2d::Ref *sender)
{
    m_character->jump();
}

void ParallaxScene::onChangeGlassesButtonClick(cocos2d::Ref *sender)
{
    m_character->switchAccessory(AccessoryType::GLASSES);
}
