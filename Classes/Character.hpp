//
//  Character.hpp
//  
//
//  Created by erhan güven on 21.12.2023.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include "cocos2d.h"

enum class AccessoryType
{
    GLASSES
};

struct AccessoryInfo
{
    cocos2d::Vec2 positionMultipler;
    float scaleMultipler;

};

struct GlassesAccessoryInfo : public AccessoryInfo
{
    GlassesAccessoryInfo()
    {
        positionMultipler = {0.44f, 0.867f};
        scaleMultipler = 0.06f;
    }
};

class Character : public cocos2d::Node
{
public:
    static Character* create(const std::string& path, const cocos2d::Vec2& position);
    void addAccessory(const std::string& path, AccessoryType accessoryType);
    void removeAccessory(AccessoryType accessoryType);
    void switchAccessory(AccessoryType accessoryType);
    void jump();

private:
    cocos2d::Sprite* m_baseSprite; //Base humanoid sprite of the character
    std::unordered_map<AccessoryType, cocos2d::Sprite*> m_accessories; //Map of worn accessories
    bool m_isJumping; //Check if character is jumping, not grounded
    bool m_isGlassesActive; //Check if wearing glasses
};

#endif /* Character_hpp */
