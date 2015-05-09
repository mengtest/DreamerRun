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
    
    auto group = this->getObjectGroup("coin");
    auto& objects = group->getObjects();
    
    Value objectsVal = Value(objects);
    CCLOG("%s", objectsVal.getDescription().c_str());

    for (auto& obj : objects)
    {
        Coin * coinTemp = Coin::create("coin.png");
        ValueMap& dict = obj.asValueMap();
        
        float x = dict["x"].asFloat();
        float y = dict["y"].asFloat();
        coinTemp->setPosition(Vec2(x,y))
                              ;
        coinVector.push_back(coinTemp);

    }
    
    
   
    
};
void TiledMap::addAllObj2Layer(Widget *mainLayer){
    ;
//    for(auto &obj:coinVector){
//        //mainLayer->addChild(obj);
//    }
    for (int i=0 ; i<coinVector.size(); i++) {
        mainLayer->addChild(coinVector[i]);
    }
    //Sprite *c = Sprite::create("coin.png");
    //mainLayer->addChild(c);
};
TiledMap* TiledMap::create(string tmxFile){

    TiledMap *ret = new (std::nothrow) TiledMap();
    if (ret->initWithTMXFile(tmxFile))
    {
        ret->autorelease();
        ret->loadAllObj();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;

}