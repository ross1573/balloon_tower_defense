#pragma once
#include "Game2D.h"

using namespace jm;


// ExtraShape : draw extra shape
class ExtraShape : virtual public Game2D {
public:
    void drawFilledRoundSquare(const RGB &color, const float &size);
    void drawFilledLine(const RGB &color, const float &width, const float &height);
};


// Block : generate Block
class Block : virtual public ExtraShape {
public:
    std::vector<std::shared_ptr<vec2>> _blocksCenter;   // contain center of the block
    std::vector<std::shared_ptr<vec2>> _blocktype;      // contain type and rotation of the block
    
    const vec2 _width = { 0.12f, 0.0f };            // width of the block of road
    const vec2 _height = { 0.0f, 0.12f };           // height of the block of road
    vec2 _blockCenter = { 0.5f, 1.12f };            // position of the road block
    float _blockRotation = 0.0f;                    // degree of the road block
    bool isBlockMade = false;                       // this is to make blocks only once during the game
    
public:
    void MakeBlockSub(bool &&typeIn);
    virtual void MakeBlock();                       // generate and insert block to the vector
};


// Time : flow time
class Time : virtual public Game2D {
private:
    int _time = 0;
    
public:
    void flowtime();                                // make time flow
    int returnTime();                               // return time value for calculation
};


// PrintDigit : print digit number
class PrintDigit : virtual public Game2D {
public:
    void DrawDigit(int digit, float scaleValue, vec2 position, RGB color);      // draw a single digit number
    void NumberDraw(int number, float scaleValue, vec2 position, RGB color);    // draw positive integer number, it's limit is 99999999
    int intpow(int num1, int num2);                                             // pow function made for int
};


// For fun
class EasterEgg {
private:
    bool _isWaveTouched1 = false;
    bool _isWaveTouched2 = false;
    bool _isWaveTouched3 = false;
    bool _isEdgeTouched1 = false;
    bool _isEdgeTouched2 = false;
    bool _activation = false;
    
public:
    int needHelp = 0;
    
    void WaveTouched1();
    void WaveTouched2();
    void WaveTouched3();
    void EdgeTouched1();
    void EdgeTouched2();
    
    void Activation();
    bool getActivation();
};
