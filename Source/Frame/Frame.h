/*
 * [[ Frames Per Second Limiter ]]
 *
 *
 * # Description
 * Limit and print FPS
 *
 * # How to limit FPS
 * 1. Generate a 'Frame' type variable
 * 2. Add 'limitFPS' function in the loop
 *
 * # Form of the constructor
 * Frame "name"("FPS limit", "Print FPS")
 *               integer      boolean
 *
 * # Note
 * 1. First recorded fps data will not be printed,
 *    due to error in data
 * 2. If the 'FPS limit' value is set to 0,
 *    FPS is not limited
 */

#pragma once

#include <GLFW/glfw3.h>

#include <iostream>
#include <thread>
#include <chrono>


class Frame {
private:
    int fps_limit;
    bool printFrameStatus;
    
    int lastTimeFPS;
    int currentTimeFPS;
    int numOfFrame;
    int correctionVal;
    double lastTimeFrame;
    double currentTimeFrame;
    
public:
    Frame(const int &fps, const bool &status);
    
    void limitFPS();
};
