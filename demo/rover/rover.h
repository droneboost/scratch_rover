#ifndef ROVER_H_
#define ROVER_H_

#include <stdint.h>

#include "motor.h"

namespace BH {

namespace {
    static const uint8_t ROVER_MODE_FORWARD             = 0;
    static const uint8_t ROVER_MODE_BACKWARD            = 1;
    static const uint8_t ROVER_MODE_LEFT_SIDEWAY        = 3;
    static const uint8_t ROVER_MODE_RIGHT_SIDEWAY       = 4;
    static const uint8_t ROVER_MODE_LEFT_DIAGONAL       = 5;
    static const uint8_t ROVER_MODE_RIGHT_DIAGONAL      = 6;
    static const uint8_t ROVER_MODE_LEFT_CONCERNING     = 7;
    static const uint8_t ROVER_MODE_RIGHT_CONCERNING    = 8;
    static const uint8_t ROVER_MODE_LEFT_TURNROUND      = 9;
    static const uint8_t ROVER_MODE_RIGHT_TURNROUND     = 10;
    static const uint8_t ROVER_MODE_LEFT_TURNFRONTAXIS  = 11;
    static const uint8_t ROVER_MODE_RIGHT_TURNFRONTAXIS = 12;
    static const uint8_t ROVER_MODE_LEFT_TURNFREARAXIS  = 13;
    static const uint8_t ROVER_MODE_RIGHT_TURNREARAXIS  = 14;
    static const uint8_t ROVER_MODE_STOP                = 99;
}

class Rover {
public:
    Rover();
    ~Rover();
    bool init();
    bool deinit();
    void forward();
    void backward();
    void leftSideway();
    void rightSideway();
    void leftDiagonal();
    void rightDiagonal();
    void leftConcerning();
    void rightConcerning();
    void leftTurnround();
    void rightTurnround();
    void leftTurnFrontAxis();
    void rightTurnFrontAxis();
    void leftTurnRearAxis();
    void rightTurnRearAxis();
    void stop();
    void powerOff();

private:
    Pin* pin1;  
    Pin* pin2;
    Pin* pin3;
    Pin* pin4;
    Pin* pin5;
    Pin* pin6;
    Pin* pin7;
    Pin* pin8;
    Pin* pwm_en_pin;
    PCA9685* pwm;

    Motor* FL;
    Motor* FR;
    Motor* RL;
    Motor* RR;

    void _setMode(uint8_t rover_mode);
};

}
#endif
