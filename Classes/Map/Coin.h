//
//  Coin.h
//  DreamerRun
//
//  Created by Eavawu on 5/5/15.
//
//

#ifndef __DreamerRun__Coin__
#define __DreamerRun__Coin__

#include <stdio.h>
#include "MHeader.h"
class Coin :public Sprite{
public:
    CREATE_FUNC(Coin);
    bool extraInit();
    void setPhysic();
    static Coin* create(const std::string& filename);
};
#endif /* defined(__DreamerRun__Coin__) */
