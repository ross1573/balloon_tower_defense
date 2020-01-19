#include "Source.h"

using namespace jm;

void Block::MakeBlockSub(bool &&typeIn) {
    auto tempVec = std::make_shared<vec2>();                                        // generate block center
    tempVec->x = this->_blockCenter.x;
    tempVec->y = this->_blockCenter.y;
    _blocksCenter.push_back(tempVec);                                               // store center of block
    
    auto tempVec2 = std::make_shared<vec2>();                                       // generate block type
    tempVec2->x = typeIn;
    tempVec2->y = this->_blockRotation;
    _blocktype.push_back(tempVec2);                                                 // store type of block
}

void Block::MakeBlock() {
    if(!isBlockMade) {
        for(int i(0); i < 5; i++) { MakeBlockSub(0); _blockCenter -= _height; }     // first straight course
    
        MakeBlockSub(1);   _blockCenter -= _width;   _blockRotation = 90.0f;        // first round course
        MakeBlockSub(0);   _blockCenter -= _width;   _blockRotation = 270.0f;
        MakeBlockSub(1);   _blockCenter += _height;  _blockRotation = 0.0f;
        MakeBlockSub(0);   _blockCenter += _height;  _blockRotation = 90.0f;
        MakeBlockSub(1);   _blockCenter -= _width;
    
        for(int i(0); i < 9; i++) { MakeBlockSub(0); _blockCenter -= _width; }      // second straight course
        _blockRotation = 180.0f;
        MakeBlockSub(1);   _blockCenter -= _height;                                 // second round course
    
        for(int i(0); i < 5; i++) { MakeBlockSub(0); _blockCenter -= _height; }     // third straight course
        _blockRotation = 270.0f;
        MakeBlockSub(1);   _blockCenter += _width;                                  // third round course
        MakeBlockSub(0);   _blockCenter += _width;   _blockRotation = 0.0f;
        MakeBlockSub(1);   _blockCenter += _height;
        
        for(int i(0); i < 2; i++) { MakeBlockSub(0); _blockCenter += _height; }     // fourth stragint course
        _blockRotation = 180.0f;
        MakeBlockSub(1);   _blockCenter += _width;   _blockRotation = 90.0f;        // fourth round course
        MakeBlockSub(0);   _blockCenter += _width;
        MakeBlockSub(1);   _blockCenter -= _height;  _blockRotation = 0.0f;
        
        for(int i(0); i < 2; i++) { MakeBlockSub(0); _blockCenter -= _height; }     // fifth straight course
        _blockRotation = 270.0f;
        MakeBlockSub(1);   _blockCenter += _width;                                  // fifth round course
        MakeBlockSub(0);   _blockCenter += _width;   _blockRotation = 0.0f;
        MakeBlockSub(1);   _blockCenter += _height;  _blockRotation = 180.0f;
        
        for(int i(0); i < 2; i++) { MakeBlockSub(0); _blockCenter += _height; }     // sixth straight course;
        
        MakeBlockSub(1);   _blockCenter += _width;   _blockRotation = 90.0f;        // sixth round course;
        MakeBlockSub(0);   _blockCenter += _width;
        MakeBlockSub(1);   _blockCenter -= _height;  _blockRotation = 0.0f;
        
        for(int i(0); i < 4; i++) { MakeBlockSub(0); _blockCenter -= _height; }     // seventh straight course
        _blockRotation = 270.0f;
        MakeBlockSub(1);   _blockCenter += _width;                                  // seventh round course
        MakeBlockSub(0);   _blockCenter += _width;   _blockRotation = 0.0f;
        MakeBlockSub(1);   _blockCenter += _height;
        
        for(int i(0); i < 3; i++) { MakeBlockSub(0); _blockCenter += _height; }     // eighth straight course
        _blockRotation = 180.0f;
        MakeBlockSub(1);   _blockCenter += _width;   _blockRotation = 90.0f;        // eighth round course
        MakeBlockSub(0);   _blockCenter += _width;
        MakeBlockSub(1);   _blockCenter -= _height;  _blockRotation = 0.0f;
        
        for(int i(0); i < 5; i++) { MakeBlockSub(0); _blockCenter -= _height; }     // ninth straight course
        
        MakeBlockSub(1);   _blockCenter -= _width;   _blockRotation = 90.0f;        // ninth round course
        
        for(int i(0); i < 5; i++) { MakeBlockSub(0); _blockCenter -= _width; }      // tenth straight course
        _blockRotation = 270.0f;
        MakeBlockSub(1);   _blockCenter += _height;  _blockRotation = 0.0f;         // tenth round course
        MakeBlockSub(0);   _blockCenter += _height;  _blockRotation = 90.0f;
        MakeBlockSub(1);   _blockCenter -= _width;
        
        for(int i(0); i < 9; i++) { MakeBlockSub(0); _blockCenter -= _width; }      // last course
        
        isBlockMade = true;
    }
}

void Time::flowtime() {
    _time += 1;                                                                     // time flows for every 1/60 second
    
    if (_time > 2000000000) _time = 0;
}

int Time::returnTime() {
    return _time;                                                                   // return time for calculation
}

void PrintDigit::DrawDigit(int digit, float scaleValue, vec2 position, RGB color) {
    beginTransformation();
    {
        translate(position);                                                        // move center
        scale(scaleValue, scaleValue);                                              // scale size
        setLineWidth(3.0f);                                                         // make thicker
        
        if      (digit == 1) {                                                      // 1
            drawLine(color, { 0.0f, -0.1f }, color, { 0.0f, 0.1f });
        }
        else if (digit == 2) {                                                      // 2
            drawLine(color, { -0.05f, 0.1f }, color, { 0.05f, 0.1f });
            drawLine(color, { 0.05f, 0.1f }, color, { 0.05f, 0.0f });
            drawLine(color, { 0.05f, 0.0f }, color, { -0.05f, 0.0f });
            drawLine(color, { -0.05f, 0.0f }, color, { -0.05f, -0.1f });
            drawLine(color, { -0.05f, -0.1f }, color, { 0.05f, -0.1f });
        }
        else if (digit == 3) {                                                      // 3
            drawLine(color, { 0.05f, -0.1f }, color, { 0.05f, 0.1f });
            drawLine(color, { -0.05f, 0.1f }, color, { 0.05f, 0.1f });
            drawLine(color, { 0.05f, 0.0f }, color, { -0.05f, 0.0f });
            drawLine(color, { -0.05f, -0.1f }, color, { 0.05f, -0.1f });
        }
        else if (digit == 4) {                                                      // 4
            drawLine(color, { 0.05f, -0.1f }, color, { 0.05f, 0.1f });
            drawLine(color, { 0.05f, 0.0f }, color, { -0.05f, 0.0f });
            drawLine(color, { -0.05f, 0.1f }, color, { -0.05f, 0.0f });
        }
        else if (digit == 5) {                                                      // 5
            drawLine(color, { -0.05f, 0.1f }, color, { 0.05f, 0.1f });
            drawLine(color, { -0.05f, 0.1f }, color, { -0.05f, 0.0f });
            drawLine(color, { 0.05f, 0.0f }, color, { -0.05f, 0.0f });
            drawLine(color, { 0.05f, 0.0f }, color, { 0.05f, -0.1f });
            drawLine(color, { -0.05f, -0.1f }, color, { 0.05f, -0.1f });
        }
        else if (digit == 6) {                                                      // 6
            drawLine(color, { -0.05f, 0.1f }, color, { 0.05f, 0.1f });
            drawLine(color, { -0.05f, 0.1f }, color, { -0.05f, -0.1f });
            drawLine(color, { 0.05f, 0.0f }, color, { -0.05f, 0.0f });
            drawLine(color, { 0.05f, 0.0f }, color, { 0.05f, -0.1f });
            drawLine(color, { -0.05f, -0.1f }, color, { 0.05f, -0.1f });
        }
        else if (digit == 7) {                                                      // 7
            drawLine(color, { 0.05f, -0.1f }, color, { 0.05f, 0.1f });
            drawLine(color, { 0.05f, 0.1f }, color, { -0.05f, 0.1f });
            drawLine(color, { -0.05f, 0.1f }, color, { -0.05f, 0.0f });
        }
        else if (digit == 8) {                                                      // 8
            drawLine(color, { -0.05f, 0.1f }, color, { 0.05f, 0.1f });
            drawLine(color, { -0.05f, 0.1f }, color, { -0.05f, -0.1f });
            drawLine(color, { 0.05f, 0.0f }, color, { -0.05f, 0.0f });
            drawLine(color, { 0.05f, 0.1f }, color, { 0.05f, -0.1f });
            drawLine(color, { -0.05f, -0.1f }, color, { 0.05f, -0.1f });
        }
        else if (digit == 9) {                                                      // 9
            drawLine(color, { 0.05f, -0.1f }, color, { 0.05f, 0.1f });
            drawLine(color, { 0.05f, 0.1f }, color, { -0.05f, 0.1f });
            drawLine(color, { -0.05f, 0.1f }, color, { -0.05f, 0.0f });
            drawLine(color, { 0.05f, 0.0f }, color, { -0.05f, 0.0f });
        }
        else if (digit == 0) {                                                      // 0
            drawLine(color, { -0.05f, 0.1f }, color, { 0.05f, 0.1f });
            drawLine(color, { -0.05f, 0.1f }, color, { -0.05f, -0.1f });
            drawLine(color, { 0.05f, 0.1f }, color, { 0.05f, -0.1f });
            drawLine(color, { -0.05f, -0.1f }, color, { 0.05f, -0.1f });
        }
    }
    endTransformation();
}

void PrintDigit::NumberDraw(int number, float scaleValue, vec2 position, RGB color) {
    if(number > 99999999) {                                                         // limit of drawing number is 99999999
        number = 99999999;
    }

    for(int i(0); i < 8; i++) {
        DrawDigit(number / intpow(10, 7 - i), scaleValue, position + vec2(0.028f * i, 0.0f), color);
        number %= intpow(10, 7 - i);
    }
}

int PrintDigit::intpow(int num1, int num2) {
    int result = 1;                                                                 // pow function for positive integer
    for(int i(0); i < num2; i++) {
        result *= num1;
    }
    
    return result;
}

void ExtraShape::drawFilledRoundSquare(const RGB &color, const float &size) {
    beginTransformation();
    {
        scale(size, size);
        beginTransformation();
        {
            translate({ 0.5f, 0.5f });
            drawFilledCircle(color, 0.25f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ -0.5f, 0.5f });
            drawFilledCircle(color, 0.25f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.5f, -0.5f });
            drawFilledCircle(color, 0.25f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ -0.5f, -0.5f });
            drawFilledCircle(color, 0.25f);
        }
        endTransformation();
        drawFilledBox(color, 1.0f, 1.5f);
        drawFilledBox(color, 1.5f, 1.0f);
    }
    endTransformation();
}

void ExtraShape::drawFilledLine(const RGB &color, const float &width, const float &height) {
    beginTransformation();
    {
        translate({ -width / 2, 0.0f });
        drawFilledCircle(color, (height / 2) - 0.0025f);
    }
    endTransformation();
    beginTransformation();
    {
        translate({ width / 2, 0.0f });
        drawFilledCircle(color, (height / 2) - 0.0025f);
    }
    endTransformation();
    drawFilledBox(color, width, height);
}

void EasterEgg::WaveTouched1() { _isWaveTouched1 = true; }
void EasterEgg::WaveTouched2() { _isWaveTouched2 = true; }
void EasterEgg::WaveTouched3() { _isWaveTouched3 = true; }
void EasterEgg::EdgeTouched1() { _isEdgeTouched1 = true; }
void EasterEgg::EdgeTouched2() { _isEdgeTouched2 = true; }

void EasterEgg::Activation() {
    if (_isWaveTouched1 &&
        _isWaveTouched2 &&
        _isWaveTouched3 &&
        _isEdgeTouched1 &&
        _isEdgeTouched2) {
        
        _activation = true;
    }
    
    if (needHelp > 9) {
        std::cout << _isEdgeTouched1 << std::endl;
        std::cout << _isEdgeTouched2 << std::endl;
        std::cout << _isWaveTouched1 << std::endl;
        std::cout << _isWaveTouched2 << std::endl;
        std::cout << _isWaveTouched3 << std::endl;
        
        needHelp = 0;
    }
}

bool EasterEgg::getActivation() {
    return _activation;
}
