//
//  MainScene.cpp
//  DreamerRun
//
//  Created by Eavawu on 4/27/15.
//
//

#include "GameMainLayer.h"


bool GameMainLayer::init() {
    addNode2Scene();
    addGamePlayer2Scene();
    addMap();
    //createPhysicBorder();
    initPhysics();
    addOrbtorCamera();
    addPhysicContactListener();
    scheduleUpdate();
    return true;
}
void GameMainLayer::addGamePlayer2Scene() {
    m_player = GamePlayer::getInstance();
    m_player->setPosition(300, 20);
    this->addChild(m_player);

};

void GameMainLayer::addNode2Scene() {
    m_uiNode = static_cast<Widget *>(CSLoader::createNode("GameLayer.csb"));
    m_uiNode->setAnchorPoint(Vec2(0.5, 0.5));
    Size nodeSize = m_uiNode->getContentSize();
    m_uiNode->setPosition(Vec2(nodeSize.width / 2, nodeSize.height / 2));
    this->addChild(m_uiNode);
};




//设置一个跟GameLayer一样大小的物理世界
void GameMainLayer::initPhysics() {
    Size nodeSize = m_uiNode->getContentSize();
    this->setContentSize(nodeSize);
    auto body = PhysicsBody::createEdgeBox(nodeSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    m_uiNode->setPhysicsBody(body);
    m_uiNode->setTag(10);
    body->setCategoryBitmask(1);    // 0001
    body->setContactTestBitmask(-1); // 0100
    body->setCollisionBitmask(-1);   // 0011
    
}


void GameMainLayer::addMap() {
    TMXTiledMap *map = TiledMapLoader::getTiledMapByLevel(1);
    Size mapSize = map->getContentSize();
    map->setPosition(mapSize.width / 2, mapSize.height / 2);
    m_uiNode->addChild(map, 2);
    
    

};
void GameMainLayer::addOrbtorCamera(){

        Size winSize = Director::getInstance()->getWinSize();
        m_camera = Camera::createOrthographic(winSize.width, winSize.height, 0, 10);
    
        m_camera->setPositionX(GamePlayer::getInstance()->getPositionX());
        m_camera->setCameraFlag(CameraFlag::USER1);
        this->addChild(m_camera);
        this->setCameraMask(2,true);

};
void GameMainLayer::update(float delay){
    m_camera->setPositionX(m_player->getPositionX());
 
};
void GameMainLayer::addPhysicContactListener(){
    physicContactListener =  PhysicListener::create();
    _eventDispatcher->addEventListenerWithSceneGraphPriority(physicContactListener, this);
    
};