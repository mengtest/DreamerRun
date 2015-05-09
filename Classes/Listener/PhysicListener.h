//
//  PhysicListener.h
//  DreamerRun
//
//  Created by Eavawu on 5/4/15.
//
//

#ifndef __DreamerRun__PhysicListener__
#define __DreamerRun__PhysicListener__
#include "MHeader.h"

#include <stdio.h>
class PhysicListener :public EventListenerPhysicsContact{
public:
    static PhysicListener* create();
    virtual bool init();
    bool onPhysicContactBegin(PhysicsContact& contact);
};
#endif /* defined(__DreamerRun__PhysicListener__) */
