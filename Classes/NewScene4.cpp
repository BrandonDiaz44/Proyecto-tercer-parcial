/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "Cementerio.h"
#include <cocostudio/SimpleAudioEngine.h>
#include "../proj.win32/NewScene.h"
#include <audio/AudioEngine.cpp>
#include "../proj.win32/NewScene2.h"
#include "../proj.win32/NewScene2.h"
#include "../proj.win32/NewScene3.h"

USING_NS_CC;

Scene* Cementerio::createScene()
{
    return Cementerio::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Cementerio::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto spriteFondo2 = Sprite::create("imagenes/KaoiFondo.png");
    spriteFondo2->setAnchorPoint(Vec2::ZERO);
    spriteFondo2->setPosition(-30, 20);
    addChild(spriteFondo2, 0);
    _gokumuerto = Sprite::create("imagenes/Gokumuerto.png");
    _gokumuerto->setAnchorPoint(Vec2::ZERO);
    _gokumuerto->setPosition(600, 150);
    addChild(_gokumuerto, 1);

    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Musica/cancion-triste-de-dragon-ball-z.MP3");

    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Musica/cancion-triste-de-dragon-ball-z.MP3", true);

    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);

    auto menu_item_5 = MenuItemImage::create("imagenes/Gameover5.png", "imagenes/Gameover6.png", CC_CALLBACK_1(Cementerio::Finish, this));
    auto menu_item_6 = MenuItemImage::create("imagenes/Menu.png", "imagenes/Menu2.png", CC_CALLBACK_1(Cementerio::Menu, this));
    auto menu_item_7 = MenuItemImage::create("imagenes/Tryagain.png", "imagenes/Tryagain2.png", CC_CALLBACK_1(Cementerio::Try, this));

    menu_item_5->setPosition(Point(visibleSize.width / 1.7, (visibleSize.height / 5) * 1));
    menu_item_6->setPosition(Point(visibleSize.width / 4, (visibleSize.height / 5) * 1));
    menu_item_7->setPosition(Point(visibleSize.width / 6, (visibleSize.height / 9.20) * 1));


    auto* menu = Menu::create(menu_item_5,menu_item_6,menu_item_7, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);

    return true;
}

void Cementerio::Finish(cocos2d::Ref* sPender)
{
    
}

void Cementerio::Menu(cocos2d::Ref* sPender)
{
    auto scene = HelloWorld::createScene();

    Director::getInstance()->pushScene(scene);
}

void Cementerio::Try(cocos2d::Ref* sPender)
{
    auto scene = NewScene::createScene();

    Director::getInstance()->pushScene(scene);
}


void Cementerio::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
