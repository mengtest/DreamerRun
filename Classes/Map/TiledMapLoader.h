//
// Created by Eavawu on 5/2/15.
//


#ifndef __TiledMapLoader_H_
#define __TiledMapLoader_H_

#include "MHeader.h"

class TiledMapLoader : public TMXTiledMap {
public:
    static TMXTiledMap *getTiledMapByFileName(string fileName);

    static TMXTiledMap *getTiledMapByLevel(int level);

private:

};


#endif //__TiledMapLoader_H_
