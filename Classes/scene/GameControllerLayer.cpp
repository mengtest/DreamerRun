//
// Created by Eavawu on 5/3/15.
//

#include "GameControllerLayer.h"

bool GameControllerLayer::init() {
    Layer::init();
    loadUI();
    setAllListner();
    return true;
};

void GameControllerLayer::loadUI() {
    m_uiNode = static_cast<Widget *>(CSLoader::createNode("GameControlLayer.csb"));
    jumpBtn = Helper::seekWidgetByName(m_uiNode, UI_JMUP_NAME);
    m_uiNode->setAnchorPoint(Vec2(0.5, 0.5));
    Size nodeSize = m_uiNode->getContentSize();
    m_uiNode->setPosition(Vec2(nodeSize.width / 2, nodeSize.height / 2));
    this->addChild(m_uiNode);

};
void GameControllerLayer::addController() {
   



};
void GameControllerLayer::onClick(Ref *pSender) {
    Widget *clickWidget = static_cast<Widget *>(pSender);
    string widgetName = clickWidget->getName();
    log("touchEvent====%s======", widgetName.c_str());
    if (widgetName == UI_JMUP_NAME) {
        EventCustom jumpEvent(NOTIFY_PLAYER_JUMP_UP);
        Director::getInstance()->getEventDispatcher()->dispatchEvent(&jumpEvent);
    }
};
void GameControllerLayer::setAllListner() {

    jumpBtn->addClickEventListener(CC_CALLBACK_1(GameControllerLayer::onClick, this));
};