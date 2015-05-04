//
//  MainScene.cpp
//  DreamerRun
//
//  Created by Eavawu on 4/27/15.
//
//

#include "MainScene.h"

MainScene *MainScene::create() {
    MainScene *ret = new MainScene();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    else {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

bool MainScene::init() {
    setAllSearchPath();
    addAllTexture();
    addNode2Scene();
    setAllListener();
    return true;
}

void MainScene::setAllListener() {
    auto beginGameBtn = Helper::seekWidgetByName(m_uiNode, START_BTN_NAME);
    beginGameBtn->addClickEventListener(CC_CALLBACK_1(MainScene::onClick, this));
};

void MainScene::onClick(Ref *pSender) {
    Widget *clickWidget = static_cast<Widget *>(pSender);
    string widgetName = clickWidget->getName();
    log("touchEvent====%s======", widgetName.c_str());
    if (widgetName == START_BTN_NAME) {
        Director::getInstance()->replaceScene(GameScene::createWithPhysics());
    }
};

void MainScene::addNode2Scene() {
    m_uiNode = static_cast<Widget *>(CSLoader::createNode("MainScene.csb"));
    m_uiNode->setAnchorPoint(Vec2(0.5, 0.5));
    Size winSize = Director::getInstance()->getWinSize();
    m_uiNode->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    this->addChild(m_uiNode);
};

void MainScene::addAllTexture() {
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("MainScene.plist", "MainScene.png");
   // TextureCache::getInstance()->reloadTexture("map01.png");
};

void MainScene::setAllSearchPath() {
    vector<string> pathVector;
    pathVector.push_back("spine");
    pathVector.push_back("res");
    pathVector.push_back("map");
    FileUtils::getInstance()->setSearchPaths(pathVector);
};