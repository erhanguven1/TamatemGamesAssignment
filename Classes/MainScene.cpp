#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene() {
    return MainScene::create();
}

bool MainScene::init() {
    if (!Scene::init()) {
        return false;
    }
    
    //Create the parallax scene, which includes three layers
    m_parallaxScene = new ParallaxScene();
    this->addChild(m_parallaxScene);
    
    //Create the gui node, it has 2 buttons inside (Jump and Change Glasses)
    m_gui = GameUI::create();
    m_gui->getJumpButton()->setCallback(CC_CALLBACK_1(ParallaxScene::onJumpButtonClick, m_parallaxScene));
    m_gui->getchangeGlassesButton()->setCallback(CC_CALLBACK_1(ParallaxScene::onChangeGlassesButtonClick, m_parallaxScene));
    this->addChild(m_gui);

    return true;
}
