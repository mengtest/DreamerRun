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
//    auto contactListener = EventListenerPhysicsContact::create();
//    contactListener->onContactBegin = CC_CALLBACK_1(PhysicsContactTest::onContactBegin, this);
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    
};
#endif /* defined(__DreamerRun__PhysicListener__) */
