//
// Created by Eavawu on 5/2/15.
//


#ifndef __TiledMapLoader_H_
#define __TiledMapLoader_H_

#include "MHeader.h"

class TiledMap : public TMXTiledMap {
public:
    static TiledMap * create(string tmxFile);
    TiledMap *getTiledMapByFileName(string fileName);

    static TiledMap *createMapByLevel(int level);
    
    void loadAllObj();

private:

};


#endif //__TiledMapLoader_H_
