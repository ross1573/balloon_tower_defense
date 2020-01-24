#pragma once
#include "Game2D.h"
#include "Source.h"

using namespace jm;


// Player : contain player info
class Player : public PrintDigit, virtual public ExtraShape, virtual public Time, public EasterEgg {
public:
    std::vector<std::shared_ptr<Player>> People;        // vector container of players
    std::vector<std::shared_ptr<vec2>> Score;           // vector container of scores
    
    int _gameStatus = 0;                                // shows which status player is in
    bool _drawTrashCan = false;                         // decide for drawing trashcan
    bool _drawTrashCanSub = false;
    bool _runStage = false;                             // decide for running stage
    
    int _playerHealth = 200;                            // player health
    int _playerMoney = 650;                             // player money
    int _playerTotalMoney = 650;                        // tatal amount of player earned money, this will be recorded on score
    int _playerStage = 1;                               // player stage, this will be recorded on score
    
public:
    void GeneratePlayer();                              // generate player, if there's already player, it does not generate more
    bool MouseInput(vec2 &&Center, vec2 &&Size);        // controll of mouse input
    
    void Menu();                                        // menu of the game
    void Start();                                       // first section of the game
    void LeaderBoard();                                 // draw and show info of leaderboard
    void InGame();                                      // controll input and draw things while in the game
    void End();                                         // when player has died
    void StartDraw();                                   // draw things in start
    void LeaderBoardDraw();                             // draw things in leaderboard
    void EndDraw();                                     // draw things in end
    
    void StartButton();                                 // draw start button
    void LeaderBoardButton();                           // draw leaderboard button
    void BackButton();                                  // draw back button
    void MoneyDraw();                                   // draw monkey
    void LifeDraw();                                    // draw life
    void StageDraw();                                   // draw stage
    void ButtonDraw();                                  // draw buttons
    
    void TableDraw();                                   // draw user interface
    void TrashcanDraw();                                // draw trashcan
    void UserInfoDraw();                                // draw info about player
    
    void ScoreSort();                                   // sort score vector
    void FullScreenMode();                              // cover outside of the game
};
