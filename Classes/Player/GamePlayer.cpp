//
// Created by Eavawu on 4/29/15.
//

#include "GamePlayer.h"

GamePlayer *GamePlayer::m_gamePlayer = NULL;

GamePlayer *GamePlayer::getInstance() {
    if (!m_gamePlayer) {
        m_gamePlayer = new GamePlayer();
        m_gamePlayer->retain();
        m_gamePlayer->init();
    }
    return m_gamePlayer;

};

GamePlayer::GamePlayer() {


};

GamePlayer::~GamePlayer() {
    m_gamePlayer->release();
    m_gamePlayer = NULL;

};

bool GamePlayer::init() {
    registerAllNotify();
    addSpineNode();
    initPhysicBody();
//    addCamera();
//    scheduleUpdate();
    return true;
};



void GamePlayer::addSpineNode() {
    this->setColor(Color3B(200, 200, 200));
    //添加spine动画，设置位置
    skeletonNode = SkeletonAnimation::createWithFile("spineboy.json", "spineboy.atlas", 0.6f);
    skeletonNode->setScale(0.5);
    Size contentSize = skeletonNode->getContentSize();
    skeletonNode->setPosition(contentSize.width / 2, contentSize.height / 2);
    this->setContentSize(contentSize);
    addChild(skeletonNode);
    //设置walk
    skeletonNode->setAnimation(0, "walk", true);
    skeletonNode->setSkin("goblin");

//    skeletonNode->setScale(0.2f);



//    skeletonNode->setStartListener([this](int trackIndex) {
//        spTrackEntry *entry = spAnimationState_getCurrent(skeletonNode->getState(), trackIndex);
//        const char *animationName = (entry && entry->animation) ? entry->animation->name : 0;
//        log("%d start: %s", trackIndex, animationName);
//    });
//    skeletonNode->setEndListener([](int trackIndex) {
//        log("%d end", trackIndex);
//    });
//    skeletonNode->setCompleteListener([](int trackIndex, int loopCount) {
//        log("%d complete: %d", trackIndex, loopCount);
//    });
//    skeletonNode->setEventListener([](int trackIndex, spEvent *event) {
//        log("%d event: %s, %d, %f, %s", trackIndex, event->data->name, event->intValue, event->floatValue, event->stringValue);
//    });
//
    skeletonNode->setMix("walk", "jump", 0.2f);
    skeletonNode->setMix("jump", "run", 0.2f);
    skeletonNode->setAnimation(0, "walk", true);
    spTrackEntry *jumpEntry = skeletonNode->addAnimation(0, "jump", false, 3);
    skeletonNode->addAnimation(0, "run", true);
//
    skeletonNode->setTrackStartListener(jumpEntry, [](int trackIndex) {
        log("jumped!");
    });
//


    EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch *touch, Event *event) -> bool {
        log("touch begin====");
        if (!skeletonNode->getDebugBonesEnabled()) {
            skeletonNode->setDebugBonesEnabled(true);

        }
        else if (skeletonNode->getTimeScale() == 1)
            skeletonNode->setTimeScale(0.3f);
        else {
            skeletonNode->setTimeScale(1);
            skeletonNode->setDebugBonesEnabled(false);
        }

        return true;
    };
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
};

void GamePlayer::loadAllSpineAnimation() {


}

void GamePlayer::registerAllNotify() {

    Director::getInstance()->getEventDispatcher()->addCustomEventListener(NOTIFY_PLAYER_RUN, std::bind(&GamePlayer::runCallBack, this, std::placeholders::_1));
    Director::getInstance()->getEventDispatcher()->addCustomEventListener(NOTIFY_PLAYER_DOUBLE_JUMP, std::bind(&GamePlayer::runCallBack, this, std::placeholders::_1));
    Director::getInstance()->getEventDispatcher()->addCustomEventListener(NOTIFY_PLAYER_JUMP_UP, std::bind(&GamePlayer::jumpUpCallBack, this, std::placeholders::_1));
    Director::getInstance()->getEventDispatcher()->addCustomEventListener(NOTIFY_PLAYER_JUMPDOWN, std::bind(&GamePlayer::jumpDownCallBack, this, std::placeholders::_1));
    Director::getInstance()->getEventDispatcher()->addCustomEventListener(NOTIFY_PLAYER_SPEED_UP, std::bind(&GamePlayer::speedUpCallBack, this, std::placeholders::_1));
    Director::getInstance()->getEventDispatcher()->addCustomEventListener(NOTIFY_PLAYER_SPEED_DOWN, std::bind(&GamePlayer::speedDownCallBack, this, std::placeholders::_1));
};

void  GamePlayer::runCallBack(EventCustom *event) {
    skeletonNode->setAnimation(0, "run", true);
};

void GamePlayer::jumpUpCallBack(EventCustom *event) {
    log("jumpUpCallBack");
    spTrackEntry *jumpEntry = skeletonNode->addAnimation(0, "jump", false, 3);
    skeletonNode->addAnimation(0, "run", true);
//
    skeletonNode->setTrackStartListener(jumpEntry, [](int trackIndex) {
        log("jumped!");

    });
//    AnimationState_isComplete();
};

void GamePlayer::jumpDownCallBack(EventCustom *event) {

};

void GamePlayer::speedUpCallBack(EventCustom *event) {

};

void GamePlayer::speedDownCallBack(EventCustom *event) {

};

void GamePlayer::doubleJumpCallBack(EventCustom *event) {

};

void GamePlayer::update(float delay) {

   m_camera->setPositionX(this->getPositionX());
};

void GamePlayer::initPhysicBody() {
    this->setContentSize(skeletonNode->getContentSize());
    PhysicsBody *m_body = PhysicsBody::createBox(skeletonNode->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, Vec2(0, 0));
    this->setPhysicsBody(m_body);
    m_body->setGravityEnable(false);
    m_body->setVelocity(Vec2(15, 0));
//    m_body->setCollisionBitmask(0xFFFFFFFF);
    m_body->setCategoryBitmask(1);    // 0001
    m_body->setContactTestBitmask(-1); // 0100
    m_body->setCollisionBitmask(-1);   // 0011
    this->setTag(2);
};