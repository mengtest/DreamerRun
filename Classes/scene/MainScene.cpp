//
//  MainScene.cpp
//  DreamerRun
//
//  Created by Eavawu on 4/27/15.
//
//

#include "MainScene.h"
MainScene * MainScene::create(){
    MainScene *ret = new  MainScene();
    if (ret && ret->init())
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
bool MainScene::init(){
    addAllTexture();
    addNode2Scene();
    return true;
}
void MainScene::addNode2Scene(){
    m_uiNode = CSLoader::createNode("res/MainScene.csb");
    m_uiNode->setAnchorPoint(Vec2(0.5,0.5));
    Size winSize = Director::getInstance()->getWinSize();
    m_uiNode->setPosition(winSize.width/2, winSize.height/2);
    this->addChild(m_uiNode);
};
void MainScene::addAllTexture(){
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/MainScene.plist", "res/MainScene.png");
};

