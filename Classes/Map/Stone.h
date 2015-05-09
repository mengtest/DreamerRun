//
//  Stone.h
//  DreamerRun
//
//  Created by Eavawu on 5/5/15.
//
//

#ifndef __DreamerRun__Stone__
#define __DreamerRun__Stone__
#include "MHeader.h"
#include <stdio.h>
class Stone :public Sprite{
public:
    CREATE_FUNC(Stone);
    virtual bool init();
    void setPhysic();
    
};
#endif /* defined(__DreamerRun__Stone__) */
