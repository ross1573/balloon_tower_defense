#include "Player.h"

void Player::GeneratePlayer() {
    if(!People.size()) {
        auto newPlayer = std::make_shared<Player>();
        People.push_back(newPlayer);
    }
}

bool Player::MouseInput(vec2 &&Center, vec2 &&Size) {
    if(isMouseButtonReleased(0)) {
        vec2 mousePos = getCursorPos();
        
        if(mousePos.x <= (Center.x + (Size.x / 2)) &&
           mousePos.x >= (Center.x - (Size.x / 2)) &&
           mousePos.y <= (Center.y + (Size.y / 2)) &&
           mousePos.y >= (Center.y - (Size.y / 2))) {
            return true;
        }
    }
    
    return false;
}

void Player::Menu() {
    if      (_gameStatus ==  0) Start();
    else if (_gameStatus ==  1) LeaderBoard();
    else if (People[People.size() - 1]->_playerHealth <= 0) End();
    else if (_gameStatus == -1) InGame();
}

void Player::Start() {
    StartDraw();
    
    if (MouseInput({  0.0f ,  0.13f }, { 0.5f , 0.24f })) _gameStatus = -1;
    if (MouseInput({ -0.13f, -0.13f }, { 0.24f, 0.24f })) _gameStatus =  1;
    if (MouseInput({  0.13f, -0.13f }, { 0.24f, 0.24f })) exit(EXIT_SUCCESS);
}

void Player::LeaderBoard() {
    LeaderBoardDraw();
    if (Score.size()) ScoreSort();
    for (int i(0); i < Score.size(); i++) {
        if (i > 4) break;
        NumberDraw(Score[i]->x, 0.2f, { -0.4f, 0.3f - (0.1f * i) }, Colors::black);
        NumberDraw(Score[i]->y, 0.2f, {  0.2f, 0.3f - (0.1f * i) }, Colors::black);
    }
    
    if (MouseInput({  0.0f , -0.4f  }, { 0.24f, 0.24f })) _gameStatus = 0;
}

void Player::InGame() {
    UserInfoDraw();
    ButtonDraw();
    if(_drawTrashCan) TrashcanDraw();
    
    if (MouseInput({ 0.845f, -0.31f }, { 0.3f, 0.08f }) &&
        !_drawTrashCanSub) {
        auto score = std::make_shared<vec2>();
        score->x = People[People.size() - 1]->_playerTotalMoney;
        score->y = People[People.size() - 1]->_playerStage;
        Score.push_back(score);
        
        this->_playerHealth = 0;
        this->_gameStatus = 0;
        this->_playerStage = 1;
        
        People.erase(People.begin(), People.end());
    }
    if (MouseInput({ 0.845f, -0.475f }, { 0.3f, 0.21f }) &&
        !_drawTrashCanSub) {
        People[People.size() - 1]->_runStage = true;
    }
    
    _drawTrashCanSub = _drawTrashCan;
    
    if (MouseInput({ -0.9f , -0.47f }, { 0.08f, 0.01f })) { WaveTouched1(); }
    if (MouseInput({ -0.53f, -0.44f }, { 0.08f, 0.01f })) { WaveTouched2(); }
    if (MouseInput({ -0.73f, -0.53f }, { 0.08f, 0.01f })) { WaveTouched3(); }
    if (MouseInput({ -0.99f, -0.99f }, { 0.1f, 0.1f })) { EdgeTouched1(); }
    if (MouseInput({ -0.99f,  0.99f }, { 0.1f, 0.1f })) { EdgeTouched2(); }
    Activation();
}

void Player::End() {
    this->_playerHealth = 0;
    this->_gameStatus = 2;
    
    auto score = std::make_shared<vec2>();
    score->x = People[People.size() - 1]->_playerTotalMoney;
    score->y = People[People.size() - 1]->_playerStage;
    Score.push_back(score);
    
    EndDraw();
    
    if (MouseInput({  0.0f , -0.38f }, { 0.24f, 0.24f })) {
        this->_gameStatus = 0;
        this->_playerStage = 1;
        People.erase(People.begin(), People.end());
    }
}

void Player::StartDraw() {
    drawFilledBox(Colors::white, 2.5f, 2.5f);
    
    StartButton();
    LeaderBoardButton();
    BackButton();
}

void Player::LeaderBoardDraw() {
    drawFilledBox(Colors::white, 2.5f, 2.5f);
    
    beginTransformation();
    {
        translate({ -0.13f, -0.27f });
        BackButton();
    }
    endTransformation();
    beginTransformation();
    {
        translate({ -0.3f, 0.5f });
        MoneyDraw();
    }
    endTransformation();
    beginTransformation();
    {
        translate({ 0.3f, 0.5f });
        StageDraw();
    }
    endTransformation();
}

void Player::EndDraw() {
    drawFilledSquare(Colors::white, 2.5f);
    beginTransformation();
    {
        translate({ -0.13f, -0.25f });
        BackButton();
    }
    endTransformation();
    
    beginTransformation();
    {
        setLineWidth(3.0f);
        scale(1.0f, 0.5f);
        drawWiredCircle(Colors::black, 0.2f);
        drawLine(Colors::black, { -0.05f, 1.0f }, Colors::black, {  0.05f, 1.0f });
        drawLine(Colors::black, {  0.05f, 0.8f }, Colors::black, {  0.05f, 1.0f });
        drawLine(Colors::black, { -0.05f, 0.8f }, Colors::black, { -0.05f, 1.0f });
        drawLine(Colors::black, {  0.15f, 0.8f }, Colors::black, {  0.05f, 0.8f });
        drawLine(Colors::black, { -0.15f, 0.8f }, Colors::black, { -0.05f, 0.8f });
        drawLine(Colors::black, {  0.15f, 0.6f }, Colors::black, {  0.15f, 0.8f });
        drawLine(Colors::black, { -0.15f, 0.6f }, Colors::black, { -0.15f, 0.8f });
        drawLine(Colors::black, {  0.15f, 0.6f }, Colors::black, {  0.05f, 0.6f });
        drawLine(Colors::black, { -0.15f, 0.6f }, Colors::black, { -0.05f, 0.6f });
        drawLine(Colors::black, {  0.05f, 0.2f }, Colors::black, {  0.05f, 0.6f });
        drawLine(Colors::black, { -0.05f, 0.2f }, Colors::black, { -0.05f, 0.6f });
        translate({ 0.0f, -0.2f });
        drawFilledBox(Colors::white, 1.0f, 0.4f);
        drawLine(Colors::black, { -0.2f, 0.2f }, Colors::black, { 0.2f, 0.2f });
    }
    endTransformation();
}

void Player::ScoreSort() {
    for (int i(0); i < Score.size() - 1; i++) {
        for (int j(i + 1); j < Score.size(); j++) {
            if (Score[i]->y < Score[j]->y) {
                vec2 tempVec = { Score[i]->x, Score[i]->y };
                Score[i]->x = Score[j]->x;
                Score[i]->y = Score[j]->y;
                Score[j]->x = tempVec.x;
                Score[j]->y = tempVec.y;
            }
        }
    }
}

void Player::StartButton() {
    beginTransformation();
    {
        setLineWidth(3.0f);
        translate({ 0.0f, 0.13f });
        drawWiredBox(Colors::black, 0.5f, 0.24f);
        beginTransformation();
        {
            rotate(270);
            drawWiredTriangle(Colors::black, 0.1f);
        }
        endTransformation();
    }
    endTransformation();
}

void Player::LeaderBoardButton() {
    beginTransformation();
    {
        setLineWidth(3.0f);
        translate({ -0.13f, -0.13f });
        drawWiredBox(Colors::black, 0.24f, 0.24f);
        drawLine(Colors::black, { -0.05f, -0.0495f }, Colors::black, { 0.05f, -0.0495f });
        drawLine(Colors::black, { -0.05f, 0.0165f }, Colors::black, { -0.017f, 0.0165f });
        drawLine(Colors::black, { -0.017f, 0.0495f }, Colors::black, { 0.017f, 0.0495f });
        drawLine(Colors::black, { 0.017f, -0.0165f }, Colors::black, { 0.05f, -0.0165f });
        drawLine(Colors::black, { -0.0495f, -0.0495f }, Colors::black, { -0.0495f, 0.0165 });
        drawLine(Colors::black, { -0.0165f, 0.0165 }, Colors::black, { -0.0165f, 0.0495 });
        drawLine(Colors::black, { 0.0165f, -0.0165 }, Colors::black, { 0.0165f, 0.0495 });
        drawLine(Colors::black, { 0.0495f, -0.0165 }, Colors::black, { 0.0495f, -0.0495 });
    }
    endTransformation();
}

void Player::BackButton() {
    beginTransformation();
    {
        setLineWidth(3.0f);
        translate({ 0.13f, -0.13f });
        drawWiredBox(Colors::black, 0.24f, 0.24f);
        drawWiredBox(Colors::black, 0.1f, 0.1f);
        beginTransformation();
        {
            translate({ 0.0252f, 0.0f });
            drawFilledBox(Colors::white, 0.054f, 0.12f);
        }
        endTransformation();
        drawLine(Colors::black, { -0.03f, 0.0f }, Colors::black, { 0.053f, 0.0f });
        drawLine(Colors::black, { 0.02f, 0.05f }, Colors::black, { 0.053f, 0.0f });
        drawLine(Colors::black, { 0.02f, -0.05f }, Colors::black, { 0.053f, 0.0f });
    }
    endTransformation();
}

void Player::TableDraw() {
    beginTransformation();
    {
        translate(vec2(0.9f, 0.0f));
        drawFilledBox(Colors::monkeyTable, 0.4f, 2.5f);
    }
    endTransformation();                                    // draw monkey table territory
    
    beginTransformation();
    {
        translate(vec2(0.9f, 0.71f));
        drawFilledBox(Colors::ground, 0.4f, 0.012f);
    }
    endTransformation();
    
    beginTransformation();
    {
        translate({ 0.0f, -0.81f });
        drawFilledBox({ 224, 224, 224 }, 2.5f, 0.4f);
    }
    endTransformation();
    beginTransformation();
    {
        translate({ -0.575f, -0.81f });
        drawFilledBox(Colors::monkeyTable, 0.024f, 0.2f);
        beginTransformation();
        {
            translate({ 0.0f, 0.1f });
            drawFilledCircle(Colors::monkeyTable, 0.01f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.0f, -0.1f });
            drawFilledCircle(Colors::monkeyTable, 0.01f);
        }
        endTransformation();
    }
    endTransformation();
}

void Player::FullScreenMode() {
    beginTransformation();
    {
        translate(vec2(-1.58f, 0.0f));
        drawFilledBox(Colors::white, 1.0f, 2.5f);
    }
    endTransformation();                                    // cover left end
    
    beginTransformation();
    {
        translate(vec2(1.58f, 0.0f));
        drawFilledBox(Colors::white, 1.0f, 2.5f);
    }
    endTransformation();                                    // cover right end
}

void Player::TrashcanDraw() {
    beginTransformation();
    {
        translate({ 0.89f, -0.805f });
        drawFilledRoundSquare(Colors::red, 0.22f);
        scale(0.5f, 0.5f);
        translate({ -0.011f, -0.01f });
        beginTransformation();
        {
            translate({ 0.0f, 0.17f});
            drawFilledBox({ 240, 240, 240 }, 0.1f, 0.04f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.0f, 0.15f });
            drawFilledBox({ 240, 240, 240 }, 0.4f, 0.02f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.0f, -0.15f });
            drawFilledBox({ 240, 240, 240 }, 0.25f, 0.02f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ -0.14f, 0.0f });
            rotate(95);
            drawFilledBox({ 240, 240, 240 }, 0.32f, 0.02f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.14f, 0.0f });
            rotate(85);
            drawFilledBox({ 240, 240, 240 }, 0.32f, 0.02f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ -0.08f, 0.0f });
            rotate(95);
            drawFilledBox({ 240, 240, 240 }, 0.2f, 0.02f);
        }
        endTransformation();
        beginTransformation();
        {
            translate({ 0.08f, 0.0f });
            rotate(85);
            drawFilledBox({ 240, 240, 240 }, 0.2f, 0.02f);
        }
        endTransformation();
        beginTransformation();
        {
            rotate(90);
            drawFilledBox({ 243, 243, 243 }, 0.18f, 0.02f);
        }
        endTransformation();
    }
    endTransformation();
}

void Player::UserInfoDraw() {
    beginTransformation();
    {
        translate({ 0.77f, 0.92f });
        scale(0.8f, 0.8f);
        MoneyDraw();
    }
    endTransformation();
    NumberDraw(People[People.size() - 1]->_playerMoney, 0.2f, { 0.84f, 0.92f }, Colors::white);
    
    if (MouseInput({ 0.77f, 0.92f }, { 0.08f, 0.08f })) needHelp += 1;
        
    beginTransformation();
    {
        translate({ 0.77f, 0.795f });
        scale(0.7f, 0.7f);
        LifeDraw();
    }
    endTransformation();
    NumberDraw(People[People.size() - 1]->_playerHealth, 0.2f, { 0.84f, 0.795f }, Colors::white);
    
    beginTransformation();
    {
        translate({ -0.97f, -0.72f });
        StageDraw();
        NumberDraw(People[People.size() - 1]->_playerStage, 0.2f, { 0.1f, 0.0f }, Colors::black);
    }
    endTransformation();
}

void Player::MoneyDraw() {
    drawFilledCircle(Colors::silver, 0.052f);
    drawFilledCircle(Colors::gold, 0.05f);
    drawWiredCircle(Colors::silver, 0.04f);
}

void Player::LifeDraw() {
    beginTransformation();
    {
        translate({ -0.026f, 0.026f });
        drawFilledCircle(Colors::red, 0.026f);
    }
    endTransformation();
    beginTransformation();
    {
        translate({ 0.026f, 0.026f });
        drawFilledCircle(Colors::red, 0.026f);
    }
    endTransformation();
    beginTransformation();
    {
        translate({ 0.0f, -0.01f });
        rotate(180);
        drawFilledTriangle(Colors::red, 0.091f);
    }
    endTransformation();
}

void Player::StageDraw() {
    drawWiredCircle(Colors::black, 0.05f);
    drawFilledStar(Colors::gold, 0.04f, 0.02f);
}

void Player::ButtonDraw() {
    if(!People[People.size() - 1]->_runStage) {
        beginTransformation();
        {
            translate(0.89f, -0.475f);
            beginTransformation();
            {
                scale(1.0f, 0.65f);
                drawFilledRoundSquare(Colors::darkwhite, 0.21f);
            }
            endTransformation();
            beginTransformation();
            {
                rotate(270);
                drawFilledTriangle(Colors::monkeyTable, 0.1f);
            }
            endTransformation();
        }
        endTransformation();
    }
    
    else {
        beginTransformation();
        {
            translate(0.89f, -0.475f);
            beginTransformation();
            {
                scale(1.0f, 0.65f);
                drawFilledRoundSquare(Colors::darkwhite, 0.21f);
            }
            endTransformation();
            beginTransformation();
            {
                translate({ 0.0f, 0.025f });
                drawFilledCircle(Colors::monkeyTable, 0.05f);
                beginTransformation();
                {
                    translate({ 0.0f, -0.055f });
                    rotate(180.0f);
                    drawFilledTriangle(Colors::monkeyTable, 0.065f);
                }
                endTransformation();
                beginTransformation();
                {
                    translate({ 0.0f, -0.1f});
                    drawFilledTriangle(Colors::monkeyTable, 0.02f);
                }
                endTransformation();
            }
            endTransformation();
        }
        endTransformation();
    }
    
    beginTransformation();
    {
        setLineWidth(5.0f);
        translate(0.89f, -0.31f);
        beginTransformation();
        {
            scale(1.0f, 0.25f);
            drawFilledRoundSquare(Colors::darkwhite, 0.21f);
        }
        endTransformation();
        beginTransformation();
        {
            translate(0.01f, 0.0f);
            scale(1.0f, 0.4f);
            drawWiredBox(Colors::monkeyTable, 0.1f, 0.1f);
            beginTransformation();
            {
                translate({ 0.0252f, 0.0f });
                drawFilledBox(Colors::darkwhite, 0.056f, 0.12f);
            }
            endTransformation();
            drawLine(Colors::monkeyTable, { -0.03f, 0.0f }, Colors::monkeyTable, { 0.053f, 0.0f });
            drawLine(Colors::monkeyTable, { 0.02f, 0.05f }, Colors::monkeyTable, { 0.053f, 0.0f });
            drawLine(Colors::monkeyTable, { 0.02f, -0.05f }, Colors::monkeyTable, { 0.053f, 0.0f });
        }
        endTransformation();
    }
    endTransformation();
}
