//
//  PhysicListener.cpp
//  DreamerRun
//
//  Created by Eavawu on 5/4/15.
//
//
#include "MainScene.h"
#include "PhysicListener.h"
bool PhysicListener::init(){
    EventListenerPhysicsContact::init();
    this->onContactBegin = CC_CALLBACK_1(PhysicListener::onPhysicContactBegin, this);
    return true;
};
bool PhysicListener::onPhysicContactBegin(PhysicsContact& contact){
    auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
    auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
    log("p=============p===%d===%d===",spriteA->getTag(),spriteB->getTag());
    if ((spriteA->getTag()==2||spriteA->getTag()==10)&&(spriteB->getTag()==2||spriteB->getTag()==10)) {
      //  Director::getInstance()->replaceScene(MainScene::create());
        log("======墙壁撞到Player======");
    }
    return true;
};
PhysicListener* PhysicListener::create()
{
    PhysicListener* obj = new (std::nothrow) PhysicListener();
    
    if (obj != nullptr && obj->init())
    {
        obj->autorelease();
        return obj;
    }
    
    CC_SAFE_DELETE(obj);
    return nullptr;
}