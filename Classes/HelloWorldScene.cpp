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
#include <cocostudio/SimpleAudioEngine.h>
#include "../proj.win32/NewScene.h"
#include <audio/AudioEngine.cpp>
#include "../proj.win32/NewScene2.h"
#include "../proj.win32/NewScene2.h"
#include "../proj.win32/NewScene3.h"
#include "../proj.win32/NewScene4.h"
#include "../proj.win32/NewScene5.h"
#include "../proj.win32/NewScene11.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto spriteFondo = Sprite::create("imagenes/fondo7.png");
    spriteFondo->setAnchorPoint(Vec2::ZERO);
    spriteFondo->setPosition(-30,20);
    addChild(spriteFondo, 0);

    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Musica/dragonball-z-chala-head-chala-cancion-intro-hd.MP3");

    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Musica/dragonball-z-chala-head-chala-cancion-intro-hd.MP3", true);

    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);

    auto menu_item_1 = MenuItemImage::create("imagenes/Play5.png","imagenes/Play6.png",CC_CALLBACK_1(HelloWorld::Play, this));
    auto menu_item_2 = MenuItemImage::create("imagenes/Hero5.png","imagenes/Hero6.png",CC_CALLBACK_1(HelloWorld::Highscores, this));
    auto menu_item_3 = MenuItemImage::create("imagenes/Villains5.png","imagenes/Villains6.png",CC_CALLBACK_1(HelloWorld::Settings, this));
    auto menu_item_4 = MenuItemImage::create("imagenes/Exit3.png", "imagenes/Exit4.png", CC_CALLBACK_1(HelloWorld::Exit, this));

    menu_item_1->setPosition(Point(visibleSize.width / 6,(visibleSize.height / 9.20) * 3));
    menu_item_2->setPosition(Point(visibleSize.width / 2.2,(visibleSize.height / 6.20) * 2));
    menu_item_3->setPosition(Point(visibleSize.width / 4,(visibleSize.height / 5) * 1));
    menu_item_4->setPosition(Point(visibleSize.width / 1.7, (visibleSize.height / 5) * 1));

    
    auto *menu = Menu::create(menu_item_1,menu_item_2, menu_item_3, menu_item_4, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);

    return true;
}

void HelloWorld::Play(cocos2d::Ref* sPender)
{
    AudioEngine::stopAll();
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Musica/ultimate-battle-theme-official-guitar-version-full-song-montagemontaje.MP3");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Musica/ultimate-battle-theme-official-guitar-version-full-song-montagemontaje.MP3", true);
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);

    auto scene = NewScene::createScene();

    Director::getInstance()->pushScene(TransitionFadeDown::create(1,scene));
}

void HelloWorld::Highscores(cocos2d::Ref* sPender)
{
    AudioEngine::stopAll();
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Musica/el-sonido-de-fondo-mas-buscado-de-dragon-ball-z-2013-hd.MP3");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Musica/el-sonido-de-fondo-mas-buscado-de-dragon-ball-z-2013-hd.MP3", true);
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
    
    auto scene = NewScene2::createScene();

    Director::getInstance()->pushScene(TransitionFadeDown::create(1, scene));
}

void HelloWorld::Settings(cocos2d::Ref* sPender)
{
    AudioEngine::stopAll();
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Musica/musica-de-combate-dragon-ball-z.MP3");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Musica/musica-de-combate-dragon-ball-z.MP3", true);
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);

    auto scene = NewScene3::createScene();

    Director::getInstance()->pushScene(TransitionFadeDown::create(1, scene));
}

void HelloWorld::Exit(cocos2d::Ref* sPender)
{
    AudioEngine::end();
    Director::getInstance()->end();

}
    

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
