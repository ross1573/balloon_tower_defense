#pragma once
#include "Game2D.h"
#include "Source.h"
#include "Balloon.h"
#include "Map.h"
#include "Player.h"

using namespace jm;


// Bullet : define Bullet
class Bullet : virtual public Time {
public:
    std::vector<std::shared_ptr<Bullet>> Bullets;               // vector container of bullets
    std::vector<std::shared_ptr<Bullet>> Explodes;              // vector container of explosive bullets
    
    vec2 _bulletOCenter = { 0.0f, 0.0f };                       // bullet original center
    vec2 _bulletCenter = { 0.0f, 0.0f };                        // bullet center
    vec2 _bulletSpeed = { 0.0f, 0.0f };                         // bullet speed
    int _bulletType = 0;                                        // type of monkey bullet is generated from
    int _bulletFrom = 0;                                        // which monkey bullet is from
    int _bulletGenerateTime = 0;                                // time of bullet generated
    float _bulletSize = 0.0f;                                   // bullet size
    
public:
    virtual void BulletDraw();                                  // virtual function for override
    template <class T>
    void BulletGenerate(T);                                     // generate bullet
    void BulletDelete();                                        // delete bullet
};

// Monkey : define Monkey
class Monkey : virtual public Block, virtual public Balloon, virtual public Player {
public:
    std::vector<std::shared_ptr<Monkey>> Monkeys;               // vector container of monkey
    std::vector<vec3> MonkeyUICenter;                           // vector container of monkey UI position
    
    vec2 _monkeyCenter = { 0.0f, 0.0f };                        // money center
    int _monkeyFireTime = 0;                                    // fire speed of monkey
    float _monkeySize = 0.0f;                                   // size of monkey
    float _monkeyRange = 0.0f;                                  // fire range of monkey
    float _explodeRange = 0.3f;                                 // exploding range
    int _monkeyRotation = 0.0f;                                 // rotation of monkey
    int _monkeyType = 0;                                        // type of monkey
    int _monkeyFireNum = 0;                                     // bullet number for single fire
    int _monkeyPopCount = 0;                                    // count of balloon pop
    int _monkeyBuyPrice = 0;                                    // buying price of monkey
    int _monkeySellPrice = 0;                                   // selling price of monkey
    int _monkeyLevelLimit = 0;                                  // level limit of monkey
    int _monkeyTime = 0;                                        // record when iteself was generated
    
    bool _isMonkeySet = false;                                  // if monkey is placed, it's value is true
    bool _isMonkeyPointed = false;                              // if monkey is pointed, it's value is true
    bool _isMonkeyBuffed = false;                               // if monkey is buffed, it's value is true
    
public:
    virtual void MonkeyDraw();                                  // draw monkey, override for multiple designs
    template <class T>
    void MonkeyGenerate(T);                                     // generates monkey
    void MonkeyDelete();                                        // delete monkey
    bool CheckPileUp(std::shared_ptr<Monkey> pos);              // check if monkey is placeable in the position
};


// dart monkey
// just ordinary monkey shooting darts
class DartMonkey : virtual public Monkey, virtual public Bullet {
public:
    DartMonkey();
    
    void MonkeyDraw() override;
    void BulletDraw() override;
};

// tack shooter
// the more bullets, the more money
class TackShooter : virtual public Monkey, virtual public Bullet {
public:
    TackShooter();
    
    void MonkeyDraw() override;
    void BulletDraw() override;
};

// missile luncher
// explosives! careful
class MissileLuncher : virtual public Monkey, virtual public Bullet {
public:
    MissileLuncher();
    
    void MonkeyDraw() override;
    void BulletDraw() override;
};

// rapid freezer
// burr...
class RapidFreezer : virtual public Monkey, virtual public Bullet {
public:
    RapidFreezer();
    
    void MonkeyDraw() override;
    void BulletDraw() override;
};

// sniper monkey
// sniipers are alwways sloow
class SniperMonkey : virtual public Monkey, virtual public Bullet {
public:
    SniperMonkey();
    
    void MonkeyDraw() override;
    void BulletDraw() override;
};

// glue monkey
// can't freeze it, but still, making it slow might be good a choice
class GlueMonkey : virtual public Monkey, virtual public Bullet {
public:
    GlueMonkey();
    
    void MonkeyDraw() override;
    void BulletDraw() override;
};

// battle ship
// Pirates!!
class BattleShip : virtual public Monkey, virtual public Bullet {
public:
    BattleShip();
    
    void MonkeyDraw() override;
    void BulletDraw() override;
};

// super monkey
// Super is always good
class SuperMonkey : virtual public Monkey, virtual public Bullet {
public:
    SuperMonkey();
    
    void MonkeyDraw() override;
    void BulletDraw() override;
};

// money factory
// money, money, money,
class MoneyFactory : virtual public Monkey {
public:
    MoneyFactory();
    
    void MonkeyDraw() override;
};

// buff monkey
// maybe monkeys need some nicotine or something
class BuffMonkey : virtual public Monkey {
public:
    BuffMonkey();
    
    void MonkeyDraw() override;
};


// general : render, move, etc
class GeneralMonkey : virtual public Monkey, public Bullet {
public:
    void DrawMonkey();                                  // draw monkeys
    void MonkeyUIDraw();                                // generate monkey UI
    template <class T>
    void MonkeyUIDrawSub(T);
    void GenerateMonkey(float type);                    // generate monkeys
    void CheckInput();                                  // check input
    void CheckToGenerateMonkey();                       // check for generating monkey
    void CheckIsMonkeyPointed();                        // check for pointing monkey
    void PlaceMonkey();                                 // place monkey, check if it's placeable
    
    void FireBullet();                                  // make monkey fire bullet
    void GenerateBullet(int type);                      // generate bullet
    void SetDirectionBullet(unsigned long i, std::list<std::shared_ptr<Balloon>>::iterator iter);    // setdirection of bullet
    void HitBalloon();                                  // calculation of when the bullet hits balloon
    void ExplodeDraw();                                 // draw explosion
    void MonkeyBuff();                                  // calculate buffed monkey
    void DrawBullet();                                  // draw bullet
};
