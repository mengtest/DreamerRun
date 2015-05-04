//
// Created by Eavawu on 5/3/15.
//


#ifndef __GameControllerLayer_H_
#define __GameControllerLayer_H_

#include "MHeader.h"

#define UI_JMUP_NAME "jump_btn"
class GameControllerLayer : public Layer {
public:

    CREATE_FUNC(GameControllerLayer);
    virtual  bool init();
private:
    void loadUI();
    void addController();
    void onClick(Ref *pSender);
    Widget *jumpBtn;
    Widget * m_uiNode;
    void setAllListner();
};


#endif //__GameControllerLayer_H_
