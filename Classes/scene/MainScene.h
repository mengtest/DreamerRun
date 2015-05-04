//
//  MainScene.h
//  DreamerRun
//
//  Created by Eavawu on 4/27/15.
//
//

#ifndef DreamerRun_MainScene_h
#define DreamerRun_MainScene_h
#include "MHeader.h"
#include "GameScene.h"
#define START_BTN_NAME "start_btn"
class MainScene :public Scene{
public:
    static MainScene * create();
    virtual bool init();
    void onClick(Ref *pSender);
private:
    void setAllSearchPath();
    void addNode2Scene();
    Widget *m_uiNode;
    void addAllTexture();
    void setAllListener();
    
};

#endif
