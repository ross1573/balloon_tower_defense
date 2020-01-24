#pragma once
#include "Game2D.h"
#include "Source.h"
#include "Player.h"

using namespace jm;


// Road : draw road
class Road : virtual public Game2D, virtual public Block {
public:    
    void StraightRoad();                            // draw straight road
    void RoundRoad();                               // draw round road
    void RoadDraw();                                // draw full road
};


// Ground : draw ground
class Ground {
public:
    void GroundDraw();                              // background
};


// Water : draw water
class Water : virtual public Block {
public:
    void WaterDraw();                               // water
};


// Map : draw everything in Map
class Map : public Road, public Ground, public Water, virtual public Player {
public:
    void DrawMap() {
        GroundDraw();                               // draw ground
        RoadDraw();                                 // draw road
        WaterDraw();                                // draw water
        TableDraw();                                // draw table
    }
};
