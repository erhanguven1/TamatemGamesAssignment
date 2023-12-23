//
//  Character.cpp
//  
//
//  Created by erhan güven on 21.12.2023.
//

#include "Character.hpp"
using namespace cocos2d;

Character *Character::create(const std::string& path, const cocos2d::Vec2& position)
{
    Character* character = new Character();
    
    // Create base sprite
    character->m_baseSprite = cocos2d::Sprite::create(path.c_str());
    
    // Check if base sprite exists
    if(character->m_baseSprite)
    {
        character->m_baseSprite->setPosition(position);
        
        // Calculate scale related to screen size
        
        float width = cocos2d::Director::getInstance()->getWinSize().width * 0.15f;
        float height = width * 2875.0f / 1630.0f;
        
        // Set character size with new width and height values
        character->m_baseSprite->setContentSize(cocos2d::Size(width, height));
        
        character->addChild(character->m_baseSprite);
        return character;
    }
    
    CC_SAFE_DELETE(character);
    return nullptr;
}

void Character::addAccessory(const std::string &path, AccessoryType accessoryType)
{
    if(m_baseSprite != nullptr)
    {        
        auto acc = cocos2d::Sprite::create(path.c_str());
        // Make sure that the accessory is in front of the base sprite
        this->addChild(acc, m_baseSprite->getLocalZOrder() + 1);
        
        // Get size values of the base sprite
        
        float characterScaleX = m_baseSprite->getScaleX();
        float characterScaleY = m_baseSprite->getScaleY();
        cocos2d::Size characterContentSize = m_baseSprite->getContentSize();
        
        AccessoryInfo accInfo;
        
        switch (accessoryType)
        {
            case AccessoryType::GLASSES:
                // Get informational values positionMultiplier and scaleMultiplier
                accInfo = GlassesAccessoryInfo();
                m_isGlassesActive = true;
                break;
        }
        
        
        // Set position of the accessory, the position is calculated using the percentage of base sprite. For example if positionMultipler.x and positionMultipler.x are both equals to .5f, it means accessory will be in the middle of the base sprite (.5 = %50)
        acc->setPosition(cocos2d::Vec2(-characterContentSize.width / 2.0f + characterContentSize.width * accInfo.positionMultipler.x, -characterContentSize.height / 2.0f + characterContentSize.height * accInfo.positionMultipler.y));
        
        // Same goes for the scale
        acc->setScale(characterScaleX * accInfo.scaleMultipler, characterScaleY * accInfo.scaleMultipler);
        
        m_accessories[accessoryType] = acc;
    }
}

void Character::removeAccessory(AccessoryType accessoryType)
{
    //Remove the accessory if exists
    if (m_accessories.find(accessoryType) != m_accessories.end())
    {
        m_accessories.at(accessoryType)->removeFromParent();
        m_accessories.erase(accessoryType);
    }
}

void Character::jump()
{ 
    if (!m_isJumping)
    {
        m_isJumping = true;
        // Jump 50 pixels upwards in 0.5 seconds
        auto jumpUp = MoveBy::create(0.5f, Vec2(0, 50));
        // Reverse it
        auto jumpDown = jumpUp->reverse();
        
        // Easing makes it look physical
        
        auto easeJumpUp = EaseSineOut::create(jumpUp);
        auto easeJumpDown = EaseSineIn::create(jumpDown);
        
        // Create the sequence. Set m_isJumping to false when it's finished
        auto jumpSequence = Sequence::create(easeJumpUp, easeJumpDown, CallFunc::create([this]() {
            m_isJumping = false;
        }), nullptr);
        this->runAction(jumpSequence);
    }
}

void Character::switchAccessory(AccessoryType accessoryType)
{
    // Wear the accessory (Actually it's only sungglasses for now) if not wearing and vice versa
    
    m_isGlassesActive = !m_isGlassesActive;
    
    if (m_accessories.find(accessoryType) != m_accessories.end())
    {
        if(!m_isGlassesActive)
        {
            m_accessories.at(accessoryType)->removeFromParent();
            m_accessories.erase(accessoryType);
        }
    }
    else
    {
        if(m_isGlassesActive)
        {
            addAccessory("Sunglasses.png", AccessoryType::GLASSES);
        }
    }
}
