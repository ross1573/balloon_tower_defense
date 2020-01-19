#include "Frame.h"

Frame::Frame(const int &fps, const bool &status)
    : fps_limit(fps), printFrameStatus(status) {
        correctionVal = 0;
        lastTimeFrame = glfwGetTime();
        lastTimeFPS = static_cast<int>(glfwGetTime()*1000);
    }

void Frame::limitFPS() {
    if (printFrameStatus) {
        numOfFrame++; currentTimeFrame = glfwGetTime();
    }
    
    if (printFrameStatus && currentTimeFrame - lastTimeFrame >= 1.0) {
        std::cout << 1000.0 / double(numOfFrame) << " ms/frame    "
        << numOfFrame << " fps" << std::endl;
        
        if      (numOfFrame > fps_limit+5) correctionVal -= 1;
        else if (numOfFrame < fps_limit-5) correctionVal += 1;
        
        numOfFrame = 0;
        lastTimeFrame = currentTimeFrame;
    }
    
    if (fps_limit) {
        currentTimeFPS = static_cast<int>(glfwGetTime()*1000);
        int differenceTime = currentTimeFPS - lastTimeFPS;
        std::this_thread::sleep_for(std::chrono::milliseconds(int(1000/(fps_limit))-differenceTime-correctionVal));
        lastTimeFPS = static_cast<int>(glfwGetTime()*1000);
    }
}
