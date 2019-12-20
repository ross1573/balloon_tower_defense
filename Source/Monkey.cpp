#include "Monkey.h"
#define _USE_MATH_DEFINES
#define M_PI       3.14159265358979323846   // pi


// ##################################
// Area to fix when making new monkey
// ##################################
void GeneralMonkey::GenerateMonkey(float type) {
    if      (type == 1) MonkeyGenerate(DartMonkey());
    else if (type == 2) MonkeyGenerate(TackShooter());
    else if (type == 3) MonkeyGenerate(MissileLuncher());
    else if (type == 4) MonkeyGenerate(RapidFreezer());
    else if (type == 5) MonkeyGenerate(SniperMonkey());
    else if (type == 6) MonkeyGenerate(GlueMonkey());
    else if (type == 7) MonkeyGenerate(BattleShip());
    else if (type == 8) MonkeyGenerate(SuperMonkey());
    else if (type == 9) MonkeyGenerate(MoneyFactory());
    else if (type == 10) MonkeyGenerate(BuffMonkey());
}

void GeneralMonkey::GenerateBullet(int type) {
    if      (type == 1) BulletGenerate(DartMonkey());
    else if (type == 2) BulletGenerate(TackShooter());
    else if (type == 3) BulletGenerate(MissileLuncher());
    else if (type == 4) BulletGenerate(RapidFreezer());
    else if (type == 5) BulletGenerate(SniperMonkey());
    else if (type == 6) BulletGenerate(GlueMonkey());
    else if (type == 7) BulletGenerate(BattleShip());
    else if (type == 8) BulletGenerate(SuperMonkey());
}
// ##################################


// ############################################
// Area to fix value of Monkey for game balance
// ############################################
DartMonkey::DartMonkey() {                              // base value of dart monkey
    _monkeySize = 0.05f;
    _monkeyFireTime = 80;
    _monkeyType = 1;
    _monkeyFireNum = 1;
    _monkeyBuyPrice = 150;
    _monkeySellPrice = 70;
    _monkeyRange = 0.4f;
    _monkeyLevelLimit = 0;
}

TackShooter::TackShooter() {                            // base value of tack shooter    
    _monkeySize = 0.05f;
    _monkeyFireTime = 170;
    _monkeyType = 2;
    _monkeyFireNum = 6;
    _monkeyBuyPrice = 250;
    _monkeySellPrice = 100;
    _monkeyRange = 0.25f;
    _monkeyLevelLimit = 3;
}

MissileLuncher::MissileLuncher() {
    _monkeySize = 0.05f;
    _monkeyFireTime = 140;
    _monkeyType = 3;
    _monkeyFireNum = 1;
    _monkeyBuyPrice = 400;
    _monkeySellPrice = 250;
    _monkeyRange = 0.4f;
    _monkeyLevelLimit = 5;
}

RapidFreezer::RapidFreezer() {
    _monkeySize = 0.05f;
    _monkeyFireTime = 250;
    _monkeyType = 4;
    _monkeyFireNum = 1;
    _monkeyBuyPrice = 475;
    _monkeySellPrice = 150;
    _monkeyRange = 0.2f;
    _monkeyLevelLimit = 10;
}

SniperMonkey::SniperMonkey() {
    _monkeySize = 0.05f;
    _monkeyFireTime = 200;
    _monkeyType = 5;
    _monkeyFireNum = 1;
    _monkeyBuyPrice = 450;
    _monkeySellPrice = 200;
    _monkeyRange = 0.7f;
    _monkeyLevelLimit = 13;
}

GlueMonkey::GlueMonkey() {
    _monkeySize = 0.05f;
    _monkeyFireTime = 70;
    _monkeyType = 6;
    _monkeyFireNum = 1;
    _monkeyBuyPrice = 650;
    _monkeySellPrice = 200;
    _monkeyRange = 0.45f;
    _monkeyLevelLimit = 15;
}

BattleShip::BattleShip() {
    _monkeySize = 0.07f;
    _monkeyFireTime = 50;
    _monkeyType = 7;
    _monkeyFireNum = 3;
    _monkeyBuyPrice = 750;
    _monkeySellPrice = 400;
    _monkeyRange = 0.45f;
    _monkeyLevelLimit = 17;
}

SuperMonkey::SuperMonkey() {
    _monkeySize = 0.05f;
    _monkeyFireTime = 20;
    _monkeyType = 8;
    _monkeyFireNum = 1;
    _monkeyBuyPrice = 1500;
    _monkeySellPrice = 1000;
    _monkeyRange = 0.65f;
    _monkeyLevelLimit = 20;
}

MoneyFactory::MoneyFactory() {
    _monkeySize = 0.05f;
    _monkeyType = 9;
    _monkeyFireNum = 500;
    _monkeyBuyPrice = 2000;
    _monkeySellPrice = 500;
    _monkeyRange = 0.05f;
    _monkeyLevelLimit = 23;
}

BuffMonkey::BuffMonkey() {
    _monkeySize = 0.05f;
    _monkeyType = 10;
    _monkeyBuyPrice = 1700;
    _monkeySellPrice = 900;
    _monkeyRange = 0.35f;
    _monkeyLevelLimit = 25;
}
// ############################################

void DartMonkey::MonkeyDraw() {
    beginTransformation();
    {
        translate(this->_monkeyCenter);
        rotate(this->_monkeyRotation);
        drawFilledCircle(Colors::lightblack, _monkeySize + 0.005f);
        drawFilledCircle(Colors::brown, _monkeySize);
    }
    endTransformation();                                // drawing dart monkey
}

void DartMonkey::BulletDraw() {
    beginTransformation();
    {
        translate(this->_bulletCenter);
        drawFilledCircle(Colors::brown, 0.005f);
    }
    endTransformation();                                // draw bullet of dart moneky
}

void TackShooter::MonkeyDraw() {
    beginTransformation();
    {
        translate(this->_monkeyCenter);
        rotate(30);
        drawFilledBox(Colors::pink, 0.02f, 0.13f);
        beginTransformation();
        {
            rotate(60);
            drawFilledBox(Colors::pink, 0.02f, 0.13f);
        }
        endTransformation();
        beginTransformation();
        {
            rotate(120);
            drawFilledBox(Colors::pink, 0.02f, 0.13f);
        }
        endTransformation();
        drawFilledCircle(Colors::lightblack, _monkeySize + 0.005f);
        drawFilledCircle(Colors::pink, _monkeySize);
    }
    endTransformation();                                // drawing monkey of tack shooter
}

void TackShooter::BulletDraw() {
    beginTransformation();
    {
        translate(this->_bulletCenter);
        drawFilledCircle(Colors::silver, 0.005f);
    }
    endTransformation();                                // drawing bullet of tack shooter
}

void MissileLuncher::MonkeyDraw() {
    beginTransformation();
    {
        translate(this->_monkeyCenter);
        rotate(this->_monkeyRotation);
        drawFilledCircle(Colors::lightblack, _monkeySize + 0.005f);
        drawFilledCircle(Colors::gray, this->_monkeySize);
        translate({ 0.0f, -0.03f });
        drawFilledTriangle(Colors::silver, 0.02f);
        translate({ 0.0f,  0.03f });
        drawFilledBox(Colors::black, 0.023f, 0.04f);
        translate({ 0.0f,  0.029f });
        drawFilledTriangle(Colors::red, 0.02f);
    }
    endTransformation();
}

void MissileLuncher::BulletDraw() {
    beginTransformation();
    {
        translate(this->_bulletCenter);
        drawFilledCircle(Colors::red, 0.005f);
    }
    endTransformation();
}

void RapidFreezer::MonkeyDraw() {
    beginTransformation();
    {
        translate(this->_monkeyCenter);
        drawFilledCircle(Colors::lightblack, _monkeySize + 0.005f);
        drawFilledCircle(Colors::ice, _monkeySize - 0.005f);
    }
    endTransformation();
}

void RapidFreezer::BulletDraw() { }

void SniperMonkey::MonkeyDraw() {
    beginTransformation();
    {
        translate(this->_monkeyCenter);
        rotate(this->_monkeyRotation);
        drawFilledCircle(Colors::lightblack, _monkeySize + 0.005f);
        drawFilledCircle(Colors::black, _monkeySize);
    }
    endTransformation();
}

void SniperMonkey::BulletDraw() {
    beginTransformation();
    {
        translate(this->_bulletCenter);
        drawFilledCircle(Colors::black, 0.005f);
    }
    endTransformation();
}

void BattleShip::MonkeyDraw() {
    beginTransformation();
    {
        translate({ this->_monkeyCenter.x - 0.01f, this->_monkeyCenter.y - 0.005f });
        rotate(_monkeyRotation);
        beginTransformation();
        {
            rotate(80);
            translate({ 0.025f, -0.035f });
            drawFilledBox(Colors::silver, 0.05f, 0.02f);
        }
        endTransformation();
        beginTransformation();
        {
            rotate(90);
            translate({ 0.02f, 0.0f });
            drawFilledBox(Colors::silver, 0.05f, 0.02f);
        }
        endTransformation();
        beginTransformation();
        {
            rotate(110);
            translate({ 0.03f, 0.025f });
            drawFilledBox(Colors::silver, 0.05f, 0.02f);
        }
        endTransformation();
        drawFilledBox(Colors::darkBrown, 0.1f, 0.05f);
        translate({ 0.06f, 0.0f });
        scale(0.7f, 1.0f);
        rotate(-90);
        drawFilledTriangle(Colors::darkBrown, 0.041f);
    }
    endTransformation();
}

void BattleShip::BulletDraw() {
    beginTransformation();
    {
        translate(this->_bulletCenter);
        drawFilledCircle(Colors::darkBrown, 0.005f);
    }
    endTransformation();
}

void GlueMonkey::MonkeyDraw() {
    beginTransformation();
    {
        translate(this->_monkeyCenter);
        rotate(this->_monkeyRotation);
        drawFilledCircle(Colors::lightblack, _monkeySize + 0.005f);
        drawFilledCircle(Colors::glue, _monkeySize);
    }
    endTransformation();
}

void GlueMonkey::BulletDraw() {
    beginTransformation();
    {
        translate(this->_bulletCenter);
        drawFilledCircle(Colors::glue, 0.005f);
    }
    endTransformation();
}

void SuperMonkey::MonkeyDraw() {
    beginTransformation();
    {
        translate(this->_monkeyCenter);
        rotate(this->_monkeyRotation);
        drawFilledCircle(Colors::lightblack, _monkeySize + 0.005f);
        drawFilledCircle(Colors::skyblue, _monkeySize);
        drawFilledStar(Colors::gold, 0.04f, 0.02f);
    }
    endTransformation();
}

void SuperMonkey::BulletDraw() {
    beginTransformation();
    {
        translate(this->_bulletCenter);
        drawFilledCircle(Colors::purple, 0.005f);
    }
    endTransformation();
}

void MoneyFactory::MonkeyDraw() {
    beginTransformation();
    {
        translate(this->_monkeyCenter);
        scale(1.3f, 1.3f);
        drawFilledBox({ 236, 217, 173 }, 0.1f, 0.07f);
        translate({ 0.0f, 0.005f });
        drawFilledBox(Colors::gray, 0.07f, 0.05f);
        translate({ 0.0f, 0.007f });
        drawFilledBox(Colors::green, 0.04f, 0.02f);
        drawWiredBox(Colors::black, 0.035f, 0.015f);
        drawWiredCircle(Colors::black, 0.005f);
    }
    endTransformation();
}

void BuffMonkey::MonkeyDraw() {
    beginTransformation();
    {
        translate(this->_monkeyCenter);
        rotate(this->_monkeyRotation);
        drawFilledCircle(Colors::lightblack, _monkeySize + 0.005f);
        drawFilledCircle(Colors::gray, _monkeySize);
        translate({ 0.0f, 0.025f });
    }
    endTransformation();
}

void Bullet::BulletDraw() { }

template <class T>
void Bullet::BulletGenerate(T) {
    for(int i(0); i < T()._monkeyFireNum; i++) {
        auto bullet = std::make_shared<T>();            // generate new bullet
        bullet->_bulletType = T()._monkeyType;
        Bullets.push_back(bullet);                      // store bullet in container
    }
}

void Bullet::BulletDelete() {
    for (int i(0); i < Bullets.size(); i++) {           // check if bullet is out of map
        if (Bullets[i]->_bulletType != 2        &&
            Bullets[i]->_bulletCenter.x >  1.2f &&
            Bullets[i]->_bulletCenter.x < -1.2f &&
            Bullets[i]->_bulletCenter.y >  1.2f &&
            Bullets[i]->_bulletCenter.y < -1.2f) {
            Bullets.erase(Bullets.begin() + i);         // if bullet gets out of map, it gets deleted
        }
        
        if (Bullets[i]->_bulletType == 2) {             // for type 2(tack shooter), delete bullet when it gets out of range
            vec2 distance = Bullets[i]->_bulletCenter - Bullets[i]->_bulletOCenter;
            
            if (powf(distance.x, 2.0f) +
               powf(distance.y, 2.0f) >
               powf(0.2f, 2.0f)) {
                Bullets.erase(Bullets.begin() + i);
            }
        }
        
        if (Bullets[i]->_bulletType == 4) {
            if (returnTime() - Bullets[i]->_bulletGenerateTime > 1) {
                Bullets.erase(Bullets.begin() + i);
            }
        }
    }
}

void Monkey::MonkeyDraw() { }                           // virtual function for overriding several monkeys

template<class T>
void Monkey::MonkeyGenerate(T) {
    if(T()._monkeyLevelLimit <= People[People.size() - 1]->_playerStage &&
       People[People.size() - 1]->_playerMoney >= T()._monkeyBuyPrice) {
        std::shared_ptr<T> monkey = std::make_shared<T>();  // generate new monkey
        monkey->_monkeyTime = returnTime();
        Monkeys.push_back(monkey);                          //store monkey in container
        People[People.size() - 1]->_playerMoney -= T()._monkeyBuyPrice;
    }
}

void Monkey::MonkeyDelete() {
    if(_gameStatus != -1) {
        Monkeys.erase(Monkeys.begin(), Monkeys.end());  // delete monkey
    }
    
    vec2 MousePos = getCursorPos(true);
    for(int i(0); i < Monkeys.size(); i++) {
        if(Monkeys[i]->_isMonkeyPointed &&
           isMouseButtonPressed(0) &&
           MousePos.x >  0.75f &&
           MousePos.y < -0.75f &&
           MousePos.y > -0.9f) {
            if (Monkeys[i]->_monkeyType == 10) {
                for (auto & ele : Monkeys) {
                    vec2 distance = Monkeys[i]->_monkeyCenter - ele->_monkeyCenter;
                    
                    if (ele->_isMonkeyBuffed &&
                        powf(distance.x, 2.0f) + powf(distance.y, 2.0f) < powf(Monkeys[i]->_monkeyRange, 2.0f)) {
                        ele->_monkeyFireTime *= 2;
                        ele->_monkeyRange /= 1.5f;
                        ele->_isMonkeyBuffed = false;
                    }
                }
            }
            
            Monkeys.erase(Monkeys.begin() + i);
            People[People.size() - 1]->_playerMoney += Monkeys[i]->_monkeySellPrice;
        }
    }
}

bool Monkey::CheckPileUp(std::shared_ptr<Monkey> monkey) {
    for (auto & ele : _blocksCenter) {                   // check if the user is trying to locate monkey on map
        if (monkey->_monkeyCenter.x - ele->x <  _width.x / 2 + monkey->_monkeySize &&
            monkey->_monkeyCenter.x - ele->x > -_width.x / 2 - monkey->_monkeySize &&
            monkey->_monkeyCenter.y - ele->y <  _height.y / 2 + monkey->_monkeySize &&
            monkey->_monkeyCenter.y - ele->y > -_height.y / 2 - monkey->_monkeySize) {
            return true;
        }
    }
    
    for (int i(0); i < Monkeys.size() - 1; i++) {        // check if the user is trying to pile up monkey
        vec2 position = monkey->_monkeyCenter - Monkeys[i]->_monkeyCenter;
        float distance = sqrtf(powf(position.x, 2.0f) + powf(position.y, 2.0f));
        
        if (distance < monkey->_monkeySize + Monkeys[i]->_monkeySize) {
            return true;
        }
    }
    
    if (monkey->_monkeyCenter.x >  0.65f  ||
        monkey->_monkeyCenter.x < -1.03f) {
        return true;
    }
    
    if (monkey->_monkeyType != 7) {
        if (monkey->_monkeyCenter.x < -0.365f &&
            monkey->_monkeyCenter.y < -0.339f) {
            return true;
        }
    }
    else if (monkey->_monkeyType == 7) {
        if (monkey->_monkeyCenter.x > -0.365f &&
            monkey->_monkeyCenter.y > -0.339f) {
            return true;
        }
    }
    
    return false;                                       // return false if the space is available for setting monkey
}

void GeneralMonkey::DrawMonkey() {
    for(auto & ele : Monkeys) {
        ele->MonkeyDraw();                              // draw monkey
    }
}

void GeneralMonkey::MonkeyUIDraw() {
    int totalBalloonPop = 0;
    for(auto & ele : Monkeys) totalBalloonPop += ele->_monkeyPopCount;
    
    beginTransformation();
    {
        translate({ -0.97f, -0.89f });
        NumberDraw(totalBalloonPop, 0.2f, { 0.1f, 0.0f }, Colors::black);
        translate({ -0.5f, -1.2f });
        DrawBalloon();
    }
    endTransformation();
    
    for(auto & ele : Monkeys) {
        if(!ele->_isMonkeySet) {
            _drawTrashCan = true;
            break;
        }
        
        if(ele->_isMonkeyPointed) {
            TrashcanDraw();
            
            beginTransformation();
            {
                translate({ -0.97f, -0.89f });
                drawFilledBox({ 224, 224, 224 }, 0.7f, 0.1f);
                NumberDraw(ele->_monkeyPopCount, 0.2f, { 0.1f, 0.0f }, Colors::black);
                translate({ -0.5f, -1.2f });
                DrawBalloon();
            }
            endTransformation();
            
            beginTransformation();
            {
                translate({ -0.44f, -0.89f });
                NumberDraw(ele->_monkeySellPrice, 0.2f, { 0.125f, 0.0f }, Colors::black);
                scale(0.7f, 0.7f);
                DartMonkey().MonkeyDraw();
                translate({ 0.07f, 0.0f });
                MoneyDraw();
            }
            endTransformation();
            
            beginTransformation();
            {
                translate({ -0.4f, -0.72f });
                NumberDraw(ele->_monkeyBuyPrice, 0.2f, { 0.085f, 0.0f }, Colors::black);
                scale(0.75f, 0.75f);
                DartMonkey().MonkeyDraw();
                translate({ -0.07f, 0.0f });
                MoneyDraw();
            }
            endTransformation();
        }
    }
    
    MonkeyUIDrawSub(DartMonkey());
    MonkeyUIDrawSub(TackShooter());
    MonkeyUIDrawSub(MissileLuncher());
    MonkeyUIDrawSub(RapidFreezer());
    MonkeyUIDrawSub(SniperMonkey());
    MonkeyUIDrawSub(GlueMonkey());
    MonkeyUIDrawSub(BattleShip());
    MonkeyUIDrawSub(SuperMonkey());
    MonkeyUIDrawSub(MoneyFactory());
    MonkeyUIDrawSub(BuffMonkey());
}

template <class T>
void GeneralMonkey::MonkeyUIDrawSub(T) {
    vec2 UIMonkeyCenter = { 0.8f, 0.6f };               // basic position of monkey UI
    
    if(T()._monkeyType % 2) {                           // calculate for monkey UI position
        UIMonkeyCenter.y += -0.18f * ((T()._monkeyType - 1) / 2);
    }
    else {
        UIMonkeyCenter.x += 0.18f;
        UIMonkeyCenter.y += -0.18f * ((T()._monkeyType - 2) / 2);
    }
    
    beginTransformation();                              // draw silver background of monkey UI
    {
        translate(UIMonkeyCenter);
        if(T()._monkeyLevelLimit <= People[People.size() - 1]->_playerStage &&
           People[People.size() - 1]->_playerMoney >= T()._monkeyBuyPrice) {
            drawFilledRoundSquare(Colors::darkwhite, 0.105f);
        }
        else {
            drawFilledRoundSquare(Colors::red, 0.105f);
            drawFilledRoundSquare(Colors::darkwhite, 0.095f);
        }
        T().MonkeyDraw();
    }
    endTransformation();
    
    if(T()._monkeyType > MonkeyUICenter.size()) {       // contain monkey UI position
        MonkeyUICenter.push_back({ UIMonkeyCenter.x, UIMonkeyCenter.y, static_cast<float>(T()._monkeyType) });
    }
}

void GeneralMonkey::CheckInput() {
    CheckToGenerateMonkey();
    CheckIsMonkeyPointed();
}
    
void GeneralMonkey::CheckToGenerateMonkey() {
    if(isMouseButtonPressedAndReleased(0)) {
        vec2 MousePos = getCursorPos(true);
        
        for(auto & ele : MonkeyUICenter) {
            if(MousePos.x >= ele.r - 0.075f &&
               MousePos.x <= ele.r + 0.075f &&
               MousePos.y >= ele.g - 0.075f &&
               MousePos.y <= ele.g + 0.075f) {
                GenerateMonkey(ele.b);
                break;
            }
        }
    }
}

void GeneralMonkey::CheckIsMonkeyPointed() {
    if(isMouseButtonReleased(0)) {
        vec2 MousePos = getCursorPos(true);
    
        for(int i(0); i < Monkeys.size(); i++) {
            Monkeys[i]->_isMonkeyPointed = false;
            
            if(powf(MousePos.x - Monkeys[i]->_monkeyCenter.x, 2.0f) +
               powf(MousePos.y - Monkeys[i]->_monkeyCenter.y, 2.0f) <
               powf(Monkeys[i]->_monkeySize, 2.0f)) {
                Monkeys[i]->_isMonkeyPointed = true;
                break;
            }
        }
    }
}

void GeneralMonkey::PlaceMonkey() {
    for(int i(0); i < Monkeys.size(); i++) {
        if(!Monkeys[i]->_isMonkeySet) {            
            Monkeys[i]->_monkeyCenter = getCursorPos(true);
            if (Monkeys[i]->_monkeyCenter.x >  1.03f) Monkeys[i]->_monkeyCenter.x =  1.03f;
            if (Monkeys[i]->_monkeyCenter.x < -1.03f) Monkeys[i]->_monkeyCenter.x = -1.03f;
            if (Monkeys[i]->_monkeyCenter.y >  0.95f) Monkeys[i]->_monkeyCenter.y =  0.95f;
            if (Monkeys[i]->_monkeyCenter.y < -0.56f) Monkeys[i]->_monkeyCenter.y = -0.56f;
            
            if(CheckPileUp(Monkeys[i])) {
                beginTransformation();
                translate(Monkeys[i]->_monkeyCenter);
                drawWiredCircle(Colors::red, Monkeys[i]->_monkeyRange);
                endTransformation();
            }
            else {
                beginTransformation();
                translate(Monkeys[i]->_monkeyCenter);
                drawWiredCircle(Colors::white, Monkeys[i]->_monkeyRange);
                endTransformation();
            
                if(isMouseButtonPressedAndReleased(0)) {
                    Monkeys[i]->_isMonkeySet = true;
                    _drawTrashCan = false;
                }
            }
            
            if(Monkeys[i]->_monkeyCenter.x >  0.75f &&
               Monkeys[i]->_monkeyCenter.y < -0.27f &&
               Monkeys[i]->_monkeyCenter.y > -0.57f) {
                if(isMouseButtonPressedAndReleased(0)) {
                    People[People.size() - 1]->_playerMoney += Monkeys[i]->_monkeyBuyPrice;
                    Monkeys.erase(Monkeys.begin() + i);
                    _drawTrashCan = false;
                }
            }
        }
    }
}

void GeneralMonkey::FireBullet() {
    for (int i(0); i < Monkeys.size(); i++) {
        if (Monkeys[i]->_monkeyType != 2 &&
            Monkeys[i]->_monkeyType != 4 &&
            Monkeys[i]->_monkeyType != 9 &&
            Monkeys[i]->_monkeyType != 10) {
            for (std::list<std::shared_ptr<Balloon>>::iterator iter = Balloons.begin(); iter != Balloons.end(); iter++) {
                vec2 distance = iter->get()->_balloonCenter - Monkeys[i]->_monkeyCenter;
                
                if (Monkeys[i]->_monkeyType == 7 &&
                    iter->get()->_balloonGlued) {
                    continue;
                }
            
                if (iter->get()->_balloonType != 5 &&
                   (returnTime() - Monkeys[i]->_monkeyTime) % Monkeys[i]->_monkeyFireTime == 0 &&
                   (powf(distance.x, 2.0f) + powf(distance.y, 2.0f) <= powf(Monkeys[i]->_monkeyRange, 2.0f)) &&
                   Monkeys[i]->_isMonkeySet &&
                   iter->get()->_balloonCenter.y < 1.0f &&
                   iter->get()->_balloonCenter.x > -1.0f) {
                    GenerateBullet(Monkeys[i]->_monkeyType);
                
                    for (int k(1); k <= Monkeys[i]->_monkeyFireNum; k++) {
                        Bullets[Bullets.size() - k]->_bulletCenter = Monkeys[i]->_monkeyCenter;
                        Bullets[Bullets.size() - k]->_bulletOCenter = Monkeys[i]->_monkeyCenter;
                        Bullets[Bullets.size() - k]->_bulletFrom = i;
                    }
                    
                    SetDirectionBullet(Bullets.size() - 1, iter);
                    
                    if (Monkeys[i]->_monkeyType == 7) {
                        Bullets[Bullets.size() - 2]->_bulletSpeed = Bullets[Bullets.size() - 1]->_bulletSpeed;
                        Bullets[Bullets.size() - 2]->_bulletSpeed.x += 0.2f;
                        Bullets[Bullets.size() - 2]->_bulletSpeed.y -= 0.1f;
                        Bullets[Bullets.size() - 3]->_bulletSpeed = Bullets[Bullets.size() - 1]->_bulletSpeed;
                        Bullets[Bullets.size() - 3]->_bulletSpeed.x -= 0.2f;
                        Bullets[Bullets.size() - 3]->_bulletSpeed.y -= 0.1f;
                    }
                    
                    if      (distance.x > 0.0f && distance.y > 0.0f)
                        Monkeys[i]->_monkeyRotation = static_cast<int>(-((atan(distance.x / distance.y) / M_PI * 180)));
                    else if (distance.x > 0.0f && distance.y < 0.0f)
                        Monkeys[i]->_monkeyRotation = static_cast<int>(-((atan(distance.y / -distance.x) / M_PI * 180) + 90));
                    else if (distance.x < 0.0f && distance.y > 0.0f)
                        Monkeys[i]->_monkeyRotation = static_cast<int>(((atan(-distance.x / distance.y) / M_PI * 180)));
                    else if (distance.x < 0.0f && distance.y < 0.0f)
                        Monkeys[i]->_monkeyRotation = static_cast<int>(((atan(distance.y / distance.x) / M_PI * 180) + 90));
                    
                    break;
                }
            }
        }
        else if (Monkeys[i]->_monkeyType == 2) {
            if ((returnTime() - Monkeys[i]->_monkeyTime) % Monkeys[i]->_monkeyFireTime == 0 &&
               Monkeys[i]->_isMonkeySet) {
                GenerateBullet(Monkeys[i]->_monkeyType);
                
                for (int k(1); k <= Monkeys[i]->_monkeyFireNum; k++) {
                    Bullets[Bullets.size() - k]->_bulletCenter = Monkeys[i]->_monkeyCenter;
                    Bullets[Bullets.size() - k]->_bulletOCenter = Monkeys[i]->_monkeyCenter;
                    Bullets[Bullets.size() - 1]->_bulletFrom = i;
                    Bullets[Bullets.size() - k]->_bulletSpeed =
                    { static_cast<float>(cos(M_PI * 2 / Monkeys[i]->_monkeyFireNum * k)), static_cast<float>(sin(M_PI * 2 / Monkeys[i]->_monkeyFireNum * k)) };
                    Bullets[Bullets.size() - k]->_bulletSpeed /= 2;
                }
            }
        }
        else if (Monkeys[i]->_monkeyType == 4) {
            if ((returnTime() - Monkeys[i]->_monkeyTime) % Monkeys[i]->_monkeyFireTime == 0 &&
               Monkeys[i]->_isMonkeySet) {
                GenerateBullet(Monkeys[i]->_monkeyType);
                
                Bullets[Bullets.size() - 1]->_bulletSize = Monkeys[i]->_monkeyRange;
                Bullets[Bullets.size() - 1]->_bulletCenter = Monkeys[i]->_monkeyCenter;
                Bullets[Bullets.size() - 1]->_bulletFrom = i;
                Bullets[Bullets.size() - 1]->_bulletGenerateTime = returnTime();
            }
        }
    }
}

void GeneralMonkey::SetDirectionBullet(unsigned long i, std::list<std::shared_ptr<Balloon> >::iterator iter) {
    if(iter != Balloons.end()) {
        vec2 dir = iter->get()->_balloonCenter - Bullets[i]->_bulletCenter;
        dir /= sqrtf(powf(dir.x, 2.0f) + powf(dir.y, 2.0f));
        Bullets[i]->_bulletSpeed = dir;
    }
}

void GeneralMonkey::HitBalloon() {
    for (int i(0); i < Bullets.size(); i++) {
        if (Bullets[i]->_bulletType != 4) {
            for (auto & ele : Balloons) {
                vec2 temp = Bullets[i]->_bulletCenter - ele->_balloonCenter;
                temp.y -= 0.025f;
                
                if (Bullets[i]->_bulletType != 3 &&
                    Bullets[i]->_bulletType != 5 &&
                    Bullets[i]->_bulletType != 6) {
                    if (powf(temp.x, 2.0f) + powf(temp.y, 2.0f) <= powf(0.05f, 2.0f)) {
                        ele->_balloonHealth -= 1;
                        if (Monkeys.size() > Bullets[i]->_bulletFrom) {
                            Monkeys[Bullets[i]->_bulletFrom]->_monkeyPopCount += 1;
                        }
                        Bullets.erase(Bullets.begin() + i);
                        People[People.size() - 1]->_playerMoney += 1;
                        People[People.size() - 1]->_playerTotalMoney += 1;
                        break;
                    }
                }
                
                else if (Bullets[i]->_bulletType == 3) {
                    if (powf(temp.x, 2.0f) + powf(temp.y, 2.0f) <= powf(0.05f, 2.0f)) {
                        for (auto & ele2 : Balloons) {
                            vec2 temp2 = Bullets[i]->_bulletCenter - ele2->_balloonCenter;
                            if (powf(temp2.x, 2.0f) + powf(temp2.y, 2.0f) <= powf(0.2f, 2.0f)) {
                                ele2->_balloonHealth -= 1;
                                if (Monkeys.size() > Bullets[i]->_bulletFrom) {
                                    Monkeys[Bullets[i]->_bulletFrom]->_monkeyPopCount += 1;
                                }
                                People[People.size() - 1]->_playerMoney += 1;
                                People[People.size() - 1]->_playerTotalMoney += 1;
                            }
                        }
                        auto newExplode = std::make_shared<Bullet>();
                        newExplode->_bulletCenter = Bullets[i]->_bulletCenter;
                        newExplode->_bulletGenerateTime = returnTime();
                        Explodes.push_back(newExplode);
                        Bullets.erase(Bullets.begin() + i);
                        break;
                    }
                }
                
                else if (Bullets[i]->_bulletType == 5) {
                    if (powf(temp.x, 2.0f) + powf(temp.y, 2.0f) <= powf(0.05f, 2.0f)) {
                        if (Monkeys.size() > Bullets[i]->_bulletFrom) {
                            Monkeys[Bullets[i]->_bulletFrom]->_monkeyPopCount += ele->_balloonHealth;
                        }
                        People[People.size() - 1]->_playerMoney += ele->_balloonHealth;
                        People[People.size() - 1]->_playerTotalMoney += ele->_balloonHealth;
                        ele->_balloonHealth -= 10;
                        Bullets.erase(Bullets.begin() + i);
                        break;
                    }
                }
                
                else if (Bullets[i]->_bulletType == 6) {
                    if (powf(temp.x, 2.0f) + powf(temp.y, 2.0f) <= powf(0.05f, 2.0f)) {
                        ele->_balloonGlued = true;
                        Bullets.erase(Bullets.begin() + i);
                        break;
                    }
                }
            }
        }
            
        else if (Bullets[i]->_bulletType == 4) {
            for (auto & ele : Balloons) {
                vec2 temp = Bullets[i]->_bulletCenter - ele->_balloonCenter;
                if (powf(temp.x, 2.0f) + powf(temp.y, 2.0f) <= powf(0.2f, 2.0f)) {
                    ele->_balloonIced = true;
                    ele->_balloonIcedTime = returnTime();
                }
            }
        }
    }
}

void GeneralMonkey::ExplodeDraw() {
    for(int i(0); i < Explodes.size(); i++) {
        if (returnTime() - Explodes[i]->_bulletGenerateTime < 15) {
            beginTransformation();
            {
                translate(Explodes[i]->_bulletCenter);
                drawFilledCircle(Colors::red, 0.2f);
            }
            endTransformation();
        }
        
        else if (returnTime() - Explodes[i]->_bulletGenerateTime > 15) {
            Explodes.erase(Explodes.begin() + i);
        }
    }
}

void GeneralMonkey::MonkeyBuff() {
    for (auto & ele : Monkeys) {
        if (ele->_monkeyType == 10 &&
            ele->_isMonkeySet) {
            for (auto & ele2 : Monkeys) {
                vec2 distance = ele2->_monkeyCenter - ele->_monkeyCenter;
                
                if (!ele2->_isMonkeyBuffed &&
                    ele2->_monkeyType != 10 &&
                    ele2->_monkeyType != 9  &&
                    powf(distance.x, 2.0f) + powf(distance.y, 2.0f) < powf(ele->_monkeyRange, 2.0f)) {
                    ele2->_monkeyFireTime /= 2;
                    ele2->_monkeyRange *= 1.5f;
                    ele2->_isMonkeyBuffed = true;
                }
                
                if (ele2->_isMonkeyBuffed &&
                    powf(distance.x, 2.0f) + powf(distance.y, 2.0f) > powf(ele->_monkeyRange, 2.0f)) {
                    ele2->_monkeyFireTime *= 2;
                    ele2->_monkeyRange /= 1.5f;
                    ele2->_isMonkeyBuffed = false;
                }
            }
        }
    }
}

void GeneralMonkey::DrawBullet() {
    for(auto & ele : Bullets) {
        ele->_bulletCenter += ele->_bulletSpeed * getTimeStep();
        ele->BulletDraw();
    }
}
