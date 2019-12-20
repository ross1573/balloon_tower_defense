#include "Map.h"

using namespace jm;

void Road::StraightRoad() {
    beginTransformation();
    {
        translate(_blockCenter);
        rotate(_blockRotation);
        beginTransformation();                                  // right line
        {
            translate({ 0.06f, 0.0f });
            drawFilledBox(Colors::silver, 0.01f, 0.12f);
        }
        endTransformation();
        beginTransformation();                                  // left line
        {
            translate({ -0.06f, 0.0f });
            drawFilledBox(Colors::silver, 0.01f, 0.12f);
        }
        endTransformation();
        drawFilledBox(Colors::asphalt, 0.12f, 0.12f);           // road
        drawFilledBox(Colors::asphalt_mline, 0.01f, 0.08f);     // middle line
    }
    endTransformation();
}

void Road::RoundRoad() {
    beginTransformation();
    {
        translate(_blockCenter);
        rotate(_blockRotation);
        beginTransformation();                                  // bottom line
        {
            rotate(270.0f);
            translate({ 0.06f, 0.0f });
            drawFilledBox(Colors::silver, 0.01f, 0.12f);
        }
        endTransformation();
        beginTransformation();                                  // right line
        {
            translate({ 0.06f, 0.0f });
            drawFilledBox(Colors::silver, 0.01f, 0.12f);
        }
        endTransformation();
        drawFilledBox(Colors::asphalt, 0.12f, 0.12f);           // road
        beginTransformation();                                  // middle line
        {
            translate({ 0.0f, 0.02f });
            drawFilledBox(Colors::asphalt_mline, 0.01f, 0.04f);
        }
        endTransformation();
        beginTransformation();
        {
            rotate(90.0f);
            translate({ 0.0f, 0.02f });
            drawFilledBox(Colors::asphalt_mline, 0.01f, 0.04f);
        }
        endTransformation();
    }
    endTransformation();
}

void Road::RoadDraw() {    
    for(int i(0); i < _blocksCenter.size(); i++) {
        if(_blocktype[i]->x) {
            _blockCenter.x = _blocksCenter[i]->x;
            _blockCenter.y = _blocksCenter[i]->y;
            _blockRotation = _blocktype[i]->y;
            RoundRoad();                                    // draw round road
        }
        else {
            _blockCenter.x = _blocksCenter[i]->x;
            _blockCenter.y = _blocksCenter[i]->y;
            _blockRotation = _blocktype[i]->y;
            StraightRoad();                                 // draw stright road
        }
    }
}

void Ground::GroundDraw() {
    drawFilledBox(Colors::ground, 2.5f, 2.5f);              // draw ground
}

void Water::WaterDraw() {
    beginTransformation();
    {
        translate(-0.72f, -0.48f);
        beginTransformation();
        {
            translate({ 0.393f, 0.178f });
            drawFilledCircle(Colors::water2, 0.02f);
        }
        endTransformation();
        drawFilledBox(Colors::water2, 0.83f, 0.35f);
        drawFilledBox(Colors::water2, 0.78f, 0.4f);         // draw water2
    }
    endTransformation();
    
    beginTransformation();
    {
        translate(-0.77f, -0.53f);
        beginTransformation();
        {
            translate({ 0.393f, 0.178f });
            drawFilledCircle(Colors::water, 0.02f);
        }
        endTransformation();
        drawFilledBox(Colors::water, 0.83f, 0.35f);
        drawFilledBox(Colors::water, 0.78f, 0.4f);          // draw water1
    }
    endTransformation();
    
    beginTransformation();
    {
        translate({ -0.9, -0.47 });
        drawFilledLine(Colors::wave, 0.08, 0.01);
    }
    endTransformation();
    beginTransformation();
    {
        translate({ -0.53, -0.44 });
        drawFilledLine(Colors::wave, 0.08, 0.01);
    }
    endTransformation();
    beginTransformation();
    {
        translate({ -0.73, -0.53 });
        drawFilledLine(Colors::wave, 0.08, 0.01);
    }
    endTransformation();
}
