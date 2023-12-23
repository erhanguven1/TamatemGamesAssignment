//
//  GameUI.cpp
//  
//
//  Created by erhan güven on 23.12.2023.
//

#include "GameUI.hpp"
using namespace cocos2d;

GameUI *GameUI::create()
{
    auto screenSize = cocos2d::Director::getInstance()->getWinSize();
    
    GameUI* gui = new GameUI();
    
    // Create the jump button
    
    auto* jumpBtn = MenuItemImage::create("JumpButton.png",
                                            "JumpButtonClicked.png");
    jumpBtn->setPosition(Vec2(screenSize.width * .15f, screenSize.height * .875f));
    jumpBtn->setScale(screenSize.width * .0001f);
    
    // Create the Change glasses button (Wears or not)

    auto* changeGlassesBtn = MenuItemImage::create("GlassesChangeButton.png",
                                            "GlassesChangeButtonClicked.png");
    changeGlassesBtn->setPosition(Vec2(screenSize.width * .3f, screenSize.height * .875f));
    changeGlassesBtn->setScale(screenSize.width * .0005f);
    
    // Create the menu using the buttons above
    
    gui->m_menu = Menu::create(jumpBtn, changeGlassesBtn, nullptr);
    gui->m_menu->setPosition(Vec2::ZERO);
    gui->addChild(gui->m_menu);
    
    gui->m_jumpButton = jumpBtn;
    gui->m_changeGlassesButton = changeGlassesBtn;
    
    return gui;
}
