//
// Created by Eavawu on 5/3/15.
//


#ifndef __GameScene_H_
#define __GameScene_H_

#include "MHeader.h"
#include "GameMainLayer.h"
#include "GameControllerLayer.h"
class GameScene :public Scene{
public:
    static GameScene * createWithPhysics();
    virtual bool initWithPhysics();
private:
    GameMainLayer *m_mainLayer;
    GameControllerLayer *m_controlLayer;
    void loadAllUI();

};


#endif //__GameScene_H_
