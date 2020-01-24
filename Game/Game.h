#pragma once
#include "Source.h"
#include "Map.h"
#include "Balloon.h"
#include "Monkey.h"
#include "Stage.h"
#include "Player.h"

using namespace jm;


// Game class
class Game : public Map, public GeneralBalloon, public GeneralMonkey, public Stage {
public:
    void update() override {
        // Source
        MakeBlock();
        flowtime();
        GeneratePlayer();

        // Map
        DrawMap();

        // Bullet
        FireBullet();
        DrawBullet();
        HitBalloon();
        BulletDelete();
        ExplodeDraw();

        // Monkey
        PlaceMonkey();
        MonkeyBuff();
        MonkeyUIDraw();
        MonkeyDelete();
        DrawMonkey();
        CheckInput();

        // Balloon
        DeleteBalloon();
        DecreaseBalloonsHealth();
        CheckDirection();
        DrawBalloons();
        IcedBalloon();
        GluedBalloon();

        // Stage
        RunStage();
        EndStage();

        // Player
        Menu();
        FullScreenMode();
    }
};
