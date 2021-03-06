//
//  Stone.cpp
//  DreamerRun
//
//  Created by Eavawu on 5/5/15.
//
//

#include "Stone.h"

bool Stone::init(){
    Sprite::init();
    setPhysic();
    return true;
}
void Stone::setPhysic(){
    this->setContentSize(this->getContentSize());
    PhysicsBody *m_body = PhysicsBody::createBox(this->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, Vec2(0, 0));
    this->setPhysicsBody(m_body);
    m_body->setGravityEnable(false);
    //m_body->applyForce(Vec2(15, 0));
    //    m_body->setCollisionBitmask(0xFFFFFFFF);
    m_body->setCategoryBitmask(1);    // 0001
    m_body->setContactTestBitmask(-1); // 0100
    m_body->setCollisionBitmask(-1);   // 0011
    this->setTag(2);
};