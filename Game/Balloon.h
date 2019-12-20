#pragma once
#include "Game2D.h"
#include "Source.h"
#include "Player.h"
#include <list>

using namespace jm;


// ==================================
// Balloon speed should not over 0.6f
// ==================================


// balloon : define basic things of balloon
class Balloon : virtual public Block, virtual public Time, virtual public Player {
public:
    std::list<std::shared_ptr<Balloon>> Balloons; // generate vector where balloon will be filled
    
    vec2 _balloonCenter = { 0.5f, 1.2f };           // center of balloon
    vec2 _balloonSpeed = { 0.0f, 0.0f };            // speed of balloon
    RGB _balloonColor = Colors::red;                // color of balloon
    int _balloonGenTime = 0;                        // generate time of balloon
    int _balloonPauseTime = 0;                      // waiting time after starting the game
    float _balloonSpeedValue = 0.0f;                // speed of balloon
    int _balloonHealth = 0;                         // health of balloon
    int _balloonType = 0;                           // type of Balloon
    int _balloonWhere = 0;                          // which block the balloon is in
    int _balloonIcedTime = 0;                       // time when the balloon got freezed
    bool _balloonIced = false;                      // is balloon freezed or not
    bool _balloonGlued = false;                     // is balloon glued or not
    const float _balloonErrValue = 0.007f;          // error value, decides the maxium speed value
    
public:
    void MakeSpeed(const float& dt);                // make speed of balloon
    virtual void DrawBalloon();                     // draw balloon
    template<class T>
    void GenerateBalloon(T);                        // generate Balloon
    template <class T1, class T2>
    void DecreaseBalloonHealth(T1, T2);             // decrease balloon health when balloon got hit
    void IcedBalloon();                             // calculate time and render of freezed balloon
    void GluedBalloon();                            // calculate time and render of glued balloon
    void CheckDirection();                          // check whether balloon is on the curve and make balloon follow the road
    void DeleteBalloon();                           // delete balloon when its health is 0 or it gets out of map
};


//===========================
//        Red Balloon
//===========================
//
// color            : red
// generate time    : 120
// pause time       : 0
// speed            : 0.1f
// health           : 1
// type             : 1
// normal balloon, so weak

class RedBalloon : virtual public Balloon {
public:
    RedBalloon();
};

//==========================
//       Blue Balloon
//==========================
//
// color            : blue
// generate time    : 60
// pause time       : 1200
// speed            : 0.2f
// health           : 2
// type             : 2
// upgraded balloon, about T-70?

class BlueBalloon : virtual public Balloon {
public:
    BlueBalloon();
};

//==========================
//      Yellow Balloon
//==========================
//
// color            : yellow
// generate time    : 40
// pause time       : 1500
// speed            : 0.3f
// health           : 3
// type             : 3
// more upgraded balloon, about T-600?

class YellowBalloon : virtual public Balloon {
public:
    YellowBalloon();
};

// =========================
//      Orange Balloon
// =========================
//
// color            : orange
// generate time    : 30
// pause time       : 1800
// speed            : 0.4f
// health           : 4
// type             : 4
// even more upgraded balloon, like a zombie
// but zombie can die right?

class OrangeBalloon : virtual public Balloon {
public:
    OrangeBalloon();
};

// =========================
//       Camo Balloon
// =========================
//
// color            : camo
// generate time    : 120
// pause time       : 0
// speed            : 0.1f
// health           : 1
// type             : 5
// camo is always good, now this balloon can sneak in
// without getting noticed. But can it pass player's eyes?

class CamoBalloon : virtual public Balloon {
public:
    CamoBalloon();
};

// =========================
//        Tank Ballon
// =========================
//
// color            : titanum
// generate time    : 240
// pause time       : 1200
// speed            : 0.05f
// health           : 100
// type             : 6
// maybe this balloon is full of titanum
// but still it's just a game isn't it?

class TankBalloon : virtual public Balloon {
public:
    TankBalloon();
};

// =========================
//       Ninja Balloon
// =========================
//
// color            : black
// generate time    : 20
// pause time       : 1500
// speed            : 0.6f
// health           : 5
// type             : 7
// ninja is here, so fast you couldn't even ca...

class NinjaBalloon : virtual public Balloon {
public:
    NinjaBalloon();
    
    void DrawBalloon() override;
};

// =========================
//       Boss Balloon
// =========================
//
// color            : boss
// generate time    : 240
// pause time       : 1800
// speed            : 0.03f
// health           : 200
// type             : 8
// boss is always the bad character,
// but can you defeat it?

class BossBalloon : virtual public Balloon {
public:
    BossBalloon();
    
    void DrawBalloon() override;
};

// =========================
//        BOB Balloon
// =========================
//
// color            : bob
// generate time    : 360
// pause time       : 2100
// speed            : 0.02f
// health           : 500
// type             : 9
// the real boss finally came up,
// but not one?

class BOBBalloon : virtual public Balloon {
public:
    BOBBalloon();
    
    void DrawBalloon() override;
};


// general : generate, render, etc
class GeneralBalloon : virtual public Balloon {    
public:
    void GenerateBalloons();                        // generate all type of Balloon
    void DecreaseBalloonsHealth();                  // check if Balloon got hit
    void DrawBalloons();                            // draw balloon and make it move
};
