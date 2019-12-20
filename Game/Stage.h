#pragma once
#include "Game2D.h"
#include "Balloon.h"
#include "Monkey.h"
#include "Player.h"


// Stage : define stage
class Stage : virtual public Balloon, virtual public Monkey, virtual public Player {
private:
    int _generateCntType1 = 0;          // count number to generate expected amount of balloon
    int _generateCntType2 = 0;
    int _generateTime = 0;              // time which only works on stage class
    
    bool _isStageRunning = true;        // decide for ending stage
    
public:
    void GenerateStage();               // generate stage
    template <class T1, class T2>
    void GenerateStageSub(T1, T2);
    void PrintMessages();
    void RunStage();                    // run stage
    void EndStage();                    // end stage
};
