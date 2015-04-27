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
class MainScene :public Scene{
public:
    static MainScene * create();
    virtual bool init();
private:
    void addNode2Scene();
    Node *m_uiNode;
    void addAllTexture();
    
};

#endif
