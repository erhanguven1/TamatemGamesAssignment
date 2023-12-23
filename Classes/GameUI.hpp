//
//  GameUI.hpp
//  
//
//  Created by erhan güven on 23.12.2023.
//

#ifndef GameUI_hpp
#define GameUI_hpp

#include <stdio.h>
#include <cocos2d.h>

class GameUI : public cocos2d::Node
{
public:
    static GameUI* create();
    inline cocos2d::MenuItemImage* getJumpButton(){ return m_jumpButton; }
    inline cocos2d::MenuItemImage* getchangeGlassesButton(){ return m_changeGlassesButton; }
private:
    cocos2d::Menu* m_menu;
    cocos2d::MenuItemImage* m_jumpButton;
    cocos2d::MenuItemImage* m_changeGlassesButton;
};

#endif /* GameUI_hpp */
