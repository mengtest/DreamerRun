//
// Created by Eavawu on 5/2/15.
//

#include "TiledMap.h"

TiledMap *TiledMap::getTiledMapByFileName(string fileName) {
};

TiledMap *TiledMap::createMapByLevel(int level) {
    string fileName = "level%d.tmx";
    char temp[100];
    sprintf(temp,fileName.c_str(), level);
    log("====%s=====",temp);
//    fileName = fileName +level+".tmx";
    TiledMap * map = TiledMap::create(temp);
    return map;
};
void TiledMap::loadAllObj(){
    
};
TiledMap* TiledMap::create(string tmxFile){

    TiledMap *ret = new (std::nothrow) TiledMap();
    if (ret->initWithTMXFile(tmxFile))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;

}