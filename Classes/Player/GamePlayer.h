//
// Created by Eavawu on 4/29/15.
//


#ifndef __GamePlayer_H_
#define __GamePlayer_H_

#include "MHeader.h"

enum PLAYER_STATE {
    RUN_STATE,
    JUMP_UP_STATE,
    JUMP_DOWN_STATE,
    DEALTH_STATE,
};

class GamePlayer : public Node {
    SkeletonAnimation *skeletonNode;

    ~GamePlayer();

    GamePlayer();

    void loadAllSpineAnimation();

    void addSpineNode();

    static GamePlayer *m_gamePlayer;

    void registerAllNotify();

    void runCallBack(EventCustom *event);

    void jumpUpCallBack(EventCustom *event);

    void jumpDownCallBack(EventCustom *event);

    void speedUpCallBack(EventCustom *event);

    void speedDownCallBack(EventCustom *event);

    void doubleJumpCallBack(EventCustom *event);

    void initPhysicBody();

    void update(float delay);

    void setMainNode(Widget *mainNode);
    Widget * mainNode;
    int initPosX,initPosY;
public:
    static GamePlayer *getInstance();
    

    virtual bool init();

};


#endif //__GamePlayer_H_
