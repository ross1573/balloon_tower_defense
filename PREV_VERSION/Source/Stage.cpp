#include "Stage.h"

void Stage::GenerateStage() {
    int StageArea = static_cast<int>(People[People.size() - 1]->_playerStage / 5);
    
    if      (StageArea == 0) GenerateStageSub(RedBalloon(), BlueBalloon());
    else if (StageArea == 1) GenerateStageSub(BlueBalloon(), YellowBalloon());
    else if (StageArea == 2) GenerateStageSub(YellowBalloon(), OrangeBalloon());
    else if (StageArea == 3) GenerateStageSub(OrangeBalloon(), CamoBalloon());
    else if (StageArea == 4) GenerateStageSub(NinjaBalloon(), TankBalloon());
    else if (StageArea == 5) GenerateStageSub(NinjaBalloon(), BossBalloon());
    else if (StageArea == 6) GenerateStageSub(TankBalloon(), BossBalloon());
    else if (StageArea == 7) GenerateStageSub(NinjaBalloon(), BOBBalloon());
    else if (StageArea == 8) GenerateStageSub(TankBalloon(), BOBBalloon());
    else if (StageArea == 9) GenerateStageSub(BossBalloon(), BOBBalloon());
    else if (StageArea >  9) GenerateStageSub(BOBBalloon(), BOBBalloon());
}

template <class T1, class T2>
void Stage::GenerateStageSub(T1, T2) {
    int StageSpecific = People[People.size() - 1]->_playerStage % 5;
    int StageArea = static_cast<int>(People[People.size() - 1]->_playerStage / 5);
    
    if (T1()._balloonType == 8 || T1()._balloonType == 9) {
        if (_generateCntType1 < (StageSpecific + StageArea) &&
            returnTime() % T1()._balloonGenTime == 0) {
            GenerateBalloon(T1());
            _generateCntType1 += 1;
            if (_generateCntType1 == StageSpecific + StageArea) _isStageRunning = false;
        }
    }
    else if (T1()._balloonType == 6 || T1()._balloonType == 7) {
        if (_generateCntType1 < (StageSpecific + People[People.size() - 1]->_playerStage) &&
            returnTime() % T1()._balloonGenTime == 0) {
            GenerateBalloon(T1());
            _generateCntType1 += 1;
            if (_generateCntType1 == (StageSpecific + People[People.size() - 1]->_playerStage)) _isStageRunning = false;
        }
    }
    else {
        if (_generateCntType1 < (5 * (StageSpecific + People[People.size() - 1]->_playerStage)) &&
            returnTime() % T1()._balloonGenTime == 0) {
            GenerateBalloon(T1());
            _generateCntType1 += 1;
            if (_generateCntType1 == 5 * (StageSpecific + People[People.size() - 1]->_playerStage)) _isStageRunning = false;
        }
    }
    
    if(T2()._balloonType == 8 || T2()._balloonType == 9) {
        if (_generateCntType2 < (StageSpecific + StageArea) &&
            _generateTime > T2()._balloonPauseTime &&
            returnTime() % T2()._balloonGenTime == 0) {
            GenerateBalloon(T2());
            _generateCntType2 += 1;
            if (_generateCntType1 == StageSpecific + StageArea) _isStageRunning = false;
        }
    }
    else if (T2()._balloonType == 6 || T2()._balloonType == 7) {
        if (_generateCntType2 < (StageSpecific + StageArea * 2) &&
            returnTime() % T2()._balloonGenTime == 0) {
            GenerateBalloon(T2());
            _generateCntType1 += 1;
            if (_generateCntType1 == (StageSpecific + People[People.size() - 1]->_playerStage)) _isStageRunning = false;
        }
    }
    else {
        if (_generateCntType2 < (10 * (StageSpecific + People[People.size() - 1]->_playerStage - 4)) &&
            _generateTime > T2()._balloonPauseTime &&
            returnTime() % T2()._balloonGenTime == 0) {
            GenerateBalloon(T2());
            _generateCntType2 += 1;
            if (_generateCntType1 == 10 * (StageSpecific + People[People.size() - 1]->_playerStage - 4)) _isStageRunning = false;
        }
    }
}

void Stage::PrintMessages() {
    int StageArea = static_cast<int>(People[People.size() - 1]->_playerStage / 5);
    
    std::cout << std::endl << "Stage " << People[People.size() - 1]->_playerStage << " Cleared!" << std::endl;
    
    if      (StageArea == 0) std::cout << "Piece of cake, isn't it?" << std::endl;
    else if (StageArea == 1) std::cout << "You would never think of dying here" << std::endl;
    else if (StageArea == 2) std::cout << "Now some exercise" << std::endl;
    else if (StageArea == 3) std::cout << "Be careful of the Camo!" << std::endl;
    else if (StageArea == 4) std::cout << "Someone drill that titanum!" << std::endl;
    else if (StageArea == 5) std::cout << "Boss alert!" << std::endl;
    else if (StageArea == 6) std::cout << "Why there's always Ninja?" << std::endl;
    else if (StageArea == 7) std::cout << "There's even a Bigger Boss?" << std::endl;
    else if (StageArea == 8) std::cout << "Now I give up..." << std::endl;
    else if (StageArea == 9) std::cout << "You might be the pro-gamer" << std::endl;
    else if (StageArea == 10) std::cout << "Have you cheated?" << std::endl;
    else if (StageArea >  11) std::cout << "Are you GOD or something?" << std::endl;
}

void Stage::RunStage() {
    if (People[People.size() - 1]->_runStage) {
        GenerateStage();
        _generateTime += 1;
    }
}

void Stage::EndStage() {
    if(Balloons.size() == 0 &&
       !_isStageRunning) {
        PrintMessages();
        
        for(auto & ele : Monkeys) if (ele->_monkeyType == 9)
            People[People.size() - 1]->_playerMoney += ele->_monkeyFireNum;
        People[People.size() - 1]->_playerStage += 1;
        _generateCntType1 = 0;
        _generateCntType2 = 0;
        _generateTime = 0;
        
        _isStageRunning = true;
        People[People.size() - 1]->_runStage = false;
    }
}
