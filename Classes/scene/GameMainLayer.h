//
//  MainScene.h
//  DreamerRun
//
//  Created by Eavawu on 4/27/15.
//
//

#ifndef DreamerRun_GameScene_h
#define DreamerRun_GameScene_h

#include "MHeader.h"
#include "GamePlayer.h"
#include "TiledMap.h"
#include "PhysicListener.h"

class GameMainLayer : public Layer {
public:
//    static Scene *createScene();xxx

    virtual bool init();
    CREATE_FUNC(GameMainLayer);
private:


    //初始化物理世界
    void initPhysics();
    //添加地图
    void addMap();
    //添加根UI到Scene
    void addNode2Scene();
    //添加玩家到Layer
    void addGamePlayer2Scene();
    //添加照相机
    void addOrbtorCamera();
    //添加物理的碰撞检测
    void addPhysicContactListener();
    
    void update(float delay);
    Camera *m_camera;
    Widget *m_uiNode;
    GamePlayer *m_player;
    
    void jumpUpCallBack(EventCustom *event);
    EventListenerPhysicsContact* physicContactListener ;

    int speed = 4 ;
    Widget *jumpNode;
//    Widget * node ;
};

#endif
