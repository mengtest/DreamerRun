//
// Created by Eavawu on 5/3/15.
//

#include "GameScene.h"
GameScene* GameScene::createWithPhysics()
{
    GameScene *ret = new (std::nothrow) GameScene();
    if (ret && ret->initWithPhysics())
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

void GameScene::loadAllUI(){
    m_mainLayer = GameMainLayer::create();
    m_controlLayer = GameControllerLayer::create();
    
    this->addChild(m_mainLayer);
    this->addChild(m_controlLayer);

};
bool GameScene::initWithPhysics(){
    Scene::initWithPhysics();
    //open debug
    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    loadAllUI();
    return true;
};