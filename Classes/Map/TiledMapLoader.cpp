//
// Created by Eavawu on 5/2/15.
//

#include "TiledMapLoader.h"

TMXTiledMap *TiledMapLoader::getTiledMapByFileName(string fileName) {
    TMXTiledMap * map = TMXTiledMap::create(fileName);
    return map;
};

TMXTiledMap *TiledMapLoader::getTiledMapByLevel(int level) {
    string fileName = "level%d.tmx";
    char temp[100];
    sprintf(temp,fileName.c_str(), level);
    log("====%s=====",temp);
//    fileName = fileName +level+".tmx";
    TMXTiledMap * map = TMXTiledMap::create(temp);
    return map;
};