#include "Balloon.h"


// ##################################
// Area to fix value for game balance
// ##################################
RedBalloon::RedBalloon() {
    this->_balloonColor = Colors::red;
    this->_balloonGenTime = 120;
    this->_balloonPauseTime = 0;
    this->_balloonSpeedValue = 0.1f;
    this->_balloonSpeed = { 0.0f, -_balloonSpeedValue };
    this->_balloonHealth = 1;
    this->_balloonType = 1;
}

BlueBalloon::BlueBalloon() {
    this->_balloonColor = Colors::blue;
    this->_balloonGenTime = 60;
    this->_balloonPauseTime = 1200;
    this->_balloonSpeedValue = 0.2f;
    this->_balloonSpeed = { 0.0f, -_balloonSpeedValue };
    this->_balloonHealth = 2;
    this->_balloonType = 2;
}

YellowBalloon::YellowBalloon() {
    this->_balloonColor = Colors::yellow;
    this->_balloonGenTime = 40;
    this->_balloonPauseTime = 1500;
    this->_balloonSpeedValue = 0.3f;
    this->_balloonSpeed = { 0.0f, -_balloonSpeedValue };
    this->_balloonHealth = 3;
    this->_balloonType = 3;
}

OrangeBalloon::OrangeBalloon() {
    this->_balloonColor = Colors::orange;
    this->_balloonGenTime = 30;
    this->_balloonPauseTime = 1800;
    this->_balloonSpeedValue = 0.4f;
    this->_balloonSpeed = { 0.0f, -_balloonSpeedValue };
    this->_balloonHealth = 4;
    this->_balloonType = 4;
}

CamoBalloon::CamoBalloon() {
    this->_balloonColor = Colors::camo;
    this->_balloonGenTime = 60;
    this->_balloonPauseTime = 0;
    this->_balloonSpeedValue = 0.2f;
    this->_balloonSpeed = { 0.0f, -_balloonSpeedValue };
    this->_balloonHealth = 1;
    this->_balloonType = 5;
}

TankBalloon::TankBalloon() {
    this->_balloonColor = Colors::titanum;
    this->_balloonGenTime = 60;
    this->_balloonPauseTime = 1200;
    this->_balloonSpeedValue = 0.2f;
    this->_balloonSpeed = { 0.0f, -_balloonSpeedValue };
    this->_balloonHealth = 30;
    this->_balloonType = 6;
}

NinjaBalloon::NinjaBalloon() {
    this->_balloonColor = Colors::black;
    this->_balloonGenTime = 20;
    this->_balloonPauseTime = 1500;
    this->_balloonSpeedValue = 0.6f;
    this->_balloonSpeed = { 0.0f, -_balloonSpeedValue };
    this->_balloonHealth = 5;
    this->_balloonType = 7;
}

BossBalloon::BossBalloon() {
    this->_balloonColor = Colors::boss;
    this->_balloonGenTime = 240;
    this->_balloonPauseTime = 1800;
    this->_balloonSpeedValue = 0.03f;
    this->_balloonSpeed = { 0.0f, -_balloonSpeedValue };
    this->_balloonHealth = 70;
    this->_balloonType = 8;
}

BOBBalloon::BOBBalloon() {
    this->_balloonColor = Colors::bob;
    this->_balloonGenTime = 360;
    this->_balloonPauseTime = 2100;
    this->_balloonSpeedValue = 0.2f;
    this->_balloonSpeed = { 0.0f, -_balloonSpeedValue };
    this->_balloonHealth = 250;
    this->_balloonType = 9;
}
// ##################################


// ###################################
// Area to fix when adding new balloon
// ###################################
void GeneralBalloon::DecreaseBalloonsHealth() {
    DecreaseBalloonHealth(BlueBalloon(), RedBalloon());
    DecreaseBalloonHealth(YellowBalloon(), BlueBalloon());
    DecreaseBalloonHealth(OrangeBalloon(), YellowBalloon());
    DecreaseBalloonHealth(NinjaBalloon(), OrangeBalloon());
    DecreaseBalloonHealth(TankBalloon(), NinjaBalloon());
    DecreaseBalloonHealth(BossBalloon(), NinjaBalloon());
    DecreaseBalloonHealth(BOBBalloon(), BossBalloon());
}

void GeneralBalloon::GenerateBalloons() {
    if(_gameStatus == -1) {
        GenerateBalloon(RedBalloon());
        GenerateBalloon(BlueBalloon());
        GenerateBalloon(YellowBalloon());
        GenerateBalloon(OrangeBalloon());
        GenerateBalloon(CamoBalloon());
        GenerateBalloon(TankBalloon());
        GenerateBalloon(NinjaBalloon());
        GenerateBalloon(BossBalloon());
        GenerateBalloon(BOBBalloon());
    }
}
// ###################################


using namespace jm;

void NinjaBalloon::DrawBalloon() {
    beginTransformation();
    {
        translate({ 0.0f, 0.025f });
        translate(_balloonCenter);                                          // upper round part
        drawFilledCircle(_balloonColor, 0.02f);
        beginTransformation();
        {
            translate({ 0.0f, -0.023f });                                  // lower triangle part
            rotate(180.0f);
            drawFilledTriangle(_balloonColor, 0.032f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.0f, -0.048f});                                      // lowest triangle part
            drawFilledTriangle(_balloonColor, 0.007);
        }
        endTransformation();
    }
    endTransformation();
}

void BossBalloon::DrawBalloon() {
    beginTransformation();
    {
        translate({ 0.0f, 0.025f });
        translate(_balloonCenter);
        if      (_balloonSpeed.y < -0.001f) rotate(180);
        else if (_balloonSpeed.y >  0.001f) rotate(0);
        else if (_balloonSpeed.x < -0.001f) { translate({ 0.0f, -0.02f }); rotate(90); }
        else if (_balloonSpeed.x >  0.001f) { translate({ 0.0f, -0.02f }); rotate(270); }
        drawFilledCircle(_balloonColor, 0.06f);
        beginTransformation();
        {
            translate({ 0.0f, -0.06f });
            rotate(180);
            drawFilledTriangle(_balloonColor, 0.09f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.0f, -0.1f });
            drawFilledTriangle(_balloonColor, 0.09f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.0f, -0.14f });
            drawFilledBox(_balloonColor, 0.11f, 0.02f);
        }
        endTransformation();
    }
    endTransformation();
}

void BOBBalloon::DrawBalloon() {
    beginTransformation();
    {
        translate({ 0.0f, 0.025f });
        translate(_balloonCenter);
        if      (_balloonSpeed.y < -0.001f) rotate(180);
        else if (_balloonSpeed.y >  0.001f) rotate(0);
        else if (_balloonSpeed.x < -0.001f) { translate({ 0.0f, -0.02f }); rotate(90); }
        else if (_balloonSpeed.x >  0.001f) { translate({ 0.0f, -0.02f }); rotate(270); }
        drawFilledCircle(_balloonColor, 0.06f);
        beginTransformation();
        {
            translate({ 0.0f, -0.06f });
            rotate(180);
            drawFilledTriangle(_balloonColor, 0.09f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.0f, -0.1f });
            drawFilledTriangle(_balloonColor, 0.09f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.0f, -0.14f });
            drawFilledBox(_balloonColor, 0.11f, 0.02f);
        }
        endTransformation();
    }
    endTransformation();
}

void Balloon::DrawBalloon() {
    beginTransformation();
    {
        translate({ 0.0f, 0.025f });
        translate(_balloonCenter);                                          // upper round part
        drawFilledCircle(_balloonColor, 0.04f);
        beginTransformation();
        {
            translate({ 0.0f, -0.045f });                                   // lower triangle part
            rotate(180.0f);
            drawFilledTriangle(_balloonColor, 0.055f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.0f, -0.09f});                                      // lowest triangle part
            drawFilledTriangle(_balloonColor, 0.017f);
        }
        endTransformation();
    }
    endTransformation();
}

void Balloon::MakeSpeed(const float& dt) {
    this->_balloonCenter += this->_balloonSpeed * dt;                       // make balloon speed
}

template<class T>
void Balloon::GenerateBalloon(T) {
    auto Balloon = std::make_shared<T>();                                   // generate Balloon in each type
    Balloons.push_back(Balloon);                                            // add it to vector
}

template <class T1, class T2>
void Balloon::DecreaseBalloonHealth(T1, T2) {
    for(std::list<std::shared_ptr<Balloon>>::iterator iter = Balloons.begin(); iter != Balloons.end(); iter++) {
        if(iter->get()->_balloonType == T1()._balloonType) {                // check balloon type to confirm that it's the right balloon to decrease
            if(iter->get()->_balloonHealth <= T2()._balloonType) {           // check if the balloon's health has decreased
                if(iter->get()->_balloonType < 6) {
                    iter->get()->_balloonColor = T2()._balloonColor;            // switch color to after type balloon
                    iter->get()->_balloonSpeedValue = T2()._balloonSpeedValue;  // switch speed value to after type balloon
                    iter->get()->_balloonType = T2()._balloonType;              // switch type value to after type balloon
                }
                
                else {
                    vec2 tempCenter = iter->get()->_balloonCenter;
                    vec2 tempSpeed = iter->get()->_balloonSpeed;
                    int tempWhere = iter->get()->_balloonWhere;
                    Balloons.erase(iter);
                    
                    auto newBalloon = std::make_shared<T2>();
                    newBalloon->_balloonCenter = tempCenter;
                    newBalloon->_balloonWhere = tempWhere;
                    if      (tempSpeed.x >  0.001f) newBalloon->_balloonSpeed = {  T2()._balloonSpeedValue, 0.0f };
                    else if (tempSpeed.x < -0.001f) newBalloon->_balloonSpeed = { -T2()._balloonSpeedValue, 0.0f };
                    else if (tempSpeed.y >  0.001f) newBalloon->_balloonSpeed = { 0.0f,  T2()._balloonSpeedValue };
                    else if (tempSpeed.y < -0.001f) newBalloon->_balloonSpeed = { 0.0f, -T2()._balloonSpeedValue };
                    Balloons.insert(iter, newBalloon);
                }
            }
        }
    }
}

void Balloon::IcedBalloon() {
    for (auto & ele : Balloons) {
        if (ele->_balloonIced) {
            if (returnTime() - ele->_balloonIcedTime > 60) {
                ele->_balloonIced = false;
            }
            
            beginTransformation();
            {
                beginTransformation();
                {
                    translate({ 0.0f, 0.025f });
                    translate(ele->_balloonCenter);
                    drawFilledCircle(Colors::ice, 0.04f);
                    beginTransformation();
                    {
                        translate({ 0.0f, -0.045f });
                        rotate(180.0f);
                        drawFilledTriangle(Colors::ice, 0.055f);
                    }
                    endTransformation();
                    beginTransformation();
                    {
                        translate({ 0.0f, -0.09f});
                        drawFilledTriangle(Colors::ice, 0.017f);
                    }
                    endTransformation();
                }
                endTransformation();
            }
            endTransformation();
        }
    }
}

void Balloon::GluedBalloon() {
    for (auto & ele : Balloons) {
        if (ele->_balloonGlued) {
            ele->_balloonSpeedValue = 0.07f;
            
            beginTransformation();
            {
                translate({ 0.0f, 0.02f });
                translate(ele->_balloonCenter);
                scale(1.0f, 0.5f);
                drawFilledCircle(Colors::glue, 0.04f);
            }
            endTransformation();
        }
    }
}

void Balloon::DeleteBalloon() {
    for(std::list<std::shared_ptr<Balloon>>::iterator iter = Balloons.begin(); iter != Balloons.end(); iter++) {
        if      (iter->get()->_balloonHealth <= 0) {                        // check if balloon's health is lower than 0
            Balloons.erase(iter);
        }
        else if (iter->get()->_balloonCenter.x <= -1.2f) {                  // check if balloon got out of map
            People[People.size() - 1]->_playerHealth -= iter->get()->_balloonHealth;
            Balloons.erase(iter);
        }
        else if (_gameStatus != -1) {
            Balloons.erase(Balloons.begin(), Balloons.end());
        }
    }
}

void Balloon::CheckDirection() {
    // check direction of balloon
    // if balloon is the center of the block, make speed head to next block center
    // _balloonErrValue decides the maximum speed of balloon
    // if speed gets over the max speed, the balloon will just past the error section
    
    for(auto & ele : Balloons) {
        if(ele->_balloonCenter.x <= _blocksCenter[ele->_balloonWhere]->x + _balloonErrValue &&
           ele->_balloonCenter.x >= _blocksCenter[ele->_balloonWhere]->x - _balloonErrValue &&
           ele->_balloonCenter.y <= _blocksCenter[ele->_balloonWhere]->y + _balloonErrValue &&
           ele->_balloonCenter.y >= _blocksCenter[ele->_balloonWhere]->y - _balloonErrValue ) {
            if(ele->_balloonWhere < _blocksCenter.size() - 1) {
                if     (ele->_balloonCenter.x <= _blocksCenter[ele->_balloonWhere + 1]->x - _balloonErrValue) {
                    ele->_balloonSpeed = {  (ele->_balloonSpeedValue), 0.0f };
                    ele->_balloonWhere += 1;
                }
                else if(ele->_balloonCenter.x >= _blocksCenter[ele->_balloonWhere + 1]->x + _balloonErrValue) {
                    ele->_balloonSpeed = { -(ele->_balloonSpeedValue), 0.0f };
                    ele->_balloonWhere += 1;
                }
                else if(ele->_balloonCenter.y <= _blocksCenter[ele->_balloonWhere + 1]->y - _balloonErrValue) {
                    ele->_balloonSpeed = { 0.0f,  (ele->_balloonSpeedValue) };
                    ele->_balloonWhere += 1;
                }
                else if(ele->_balloonCenter.y >= _blocksCenter[ele->_balloonWhere + 1]->y + _balloonErrValue) {
                    ele->_balloonSpeed = { 0.0f, -(ele->_balloonSpeedValue) };
                    ele->_balloonWhere += 1;
                }
            }
        }
    }
}

void GeneralBalloon::DrawBalloons() {
    srand((unsigned)time(NULL));

    for(auto & ele : Balloons) {
        if (getActivation()) ele->_balloonColor = { rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1 };
        if (!ele->_balloonIced) ele->MakeSpeed(getTimeStep());          // make balloon go

        ele->DrawBalloon();                                             // draw balloon
    }
}
