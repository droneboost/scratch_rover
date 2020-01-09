#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "rover.h"

using namespace BH;

namespace {
    static const Motor::MotorMode rover_movement_mode[][4] = {
        /* FL                                  FR                                   RL                                   RR                                                            */
        {Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeForward }, /* forward               */
        {Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeBackward}, /* backward              */
        {Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeBackward}, /* left sideway          */
        {Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeForward }, /* right sideway         */
        {Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeStop    }, /* left diagonal         */
        {Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeForward }, /* right diagonal        */
        {Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeStop    }, /* left concerning       */
        {Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeForward }, /* right concerning      */
        {Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeForward }, /* left turnround        */
        {Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeBackward}, /* right turnround       */
        {Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeForward }, /* left turn front axis  */
        {Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeBackward}, /* right turn front axis */
        {Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeStop    }, /* left turn rear axis   */
        {Motor::MotorMode::MotorModeForward,  Motor::MotorMode::MotorModeBackward, Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeStop    }, /* right turn rear axis  */
        {Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeStop,     Motor::MotorMode::MotorModeStop    }  /* stop                  */
    };

    static const uint8_t ENA = 0; // PWM channel 0
    static const uint8_t ENB = 1; // PWM channel 1
    static const uint8_t ENC = 2; // PWM channel 2
    static const uint8_t END = 3; // PWM channel 3

    static const uint8_t PWM_EN_PIN = RPI_GPIO_4;
    static const uint8_t INT1 = RPI_GPIO_5;
    static const uint8_t INT2 = RPI_GPIO_6;
    static const uint8_t INT3 = RPI_GPIO_12;
    static const uint8_t INT4 = RPI_GPIO_20;
    static const uint8_t INT5 = RPI_GPIO_19;
    static const uint8_t INT6 = RPI_GPIO_13;
    static const uint8_t INT7 = RPI_GPIO_21;
    static const uint8_t INT8 = RPI_GPIO_26;
}

Rover::Rover()
{
}

Rover::~Rover()
{
    deinit();
}

bool Rover::init()
{
    pin1 = new Pin(INT1); // Pin init inside Motor class init()  
    pin2 = new Pin(INT2);
    pin3 = new Pin(INT3);
    pin4 = new Pin(INT4);
    pin5 = new Pin(INT5);
    pin6 = new Pin(INT6);
    pin7 = new Pin(INT7);
    pin8 = new Pin(INT8);

    pwm_en_pin = new Pin(PWM_EN_PIN);
    if (!pwm_en_pin->init()) {
        printf("Motor PWM Enable pin not set. Are you root\n");
        return 0;
    }
    pwm_en_pin->setMode(Pin::GpioModeOutput);
    pwm_en_pin->write(0); /* drive Output Enable low */

    pwm = new PCA9685();
    if (!pwm->init()) {
        printf("Motor PWM init failed. Are you root\n");
        return 0;
    }
 
    pwm->setFrequency(100);
    printf("Motor PWM set frequency %f\n", pwm->getFrequency());

    FL =new Motor(*pin1, *pin2, *pwm, ENA, Motor::MotorRole::MotorRoleFrontLeft);
    FR =new Motor(*pin3, *pin4, *pwm, ENB, Motor::MotorRole::MotorRoleFrontRight);
    RL =new Motor(*pin5, *pin6, *pwm, ENC, Motor::MotorRole::MotorRoleRearLeft);
    RR =new Motor(*pin7, *pin8, *pwm, END, Motor::MotorRole::MotorRoleRearRight);

    return 1;
}

bool Rover::deinit()
{
    if(FL != NULL) delete FL;
    if(FR != NULL) delete FR;
    if(RL != NULL) delete RL;
    if(RR != NULL) delete RR;
    if(pwm != NULL) delete pwm;
    if(pwm_en_pin != NULL) delete pwm_en_pin;
    if(pin1 != NULL) delete pin1;
    if(pin2 != NULL) delete pin2;
    if(pin3 != NULL) delete pin3;
    if(pin4 != NULL) delete pin4;
    if(pin5 != NULL) delete pin5;
    if(pin6 != NULL) delete pin6;
    if(pin7 != NULL) delete pin7;
    if(pin8 != NULL) delete pin8;
    printf("Rover deinit\n");
    return 1;
}

void Rover::_setMode(uint8_t rover_move_mode)
{
    if(rover_move_mode < ROVER_MODE_FORWARD || rover_move_mode > ROVER_MODE_STOP) {
        printf("set Rover movement mode error!");
    }

    FL->setMode(rover_movement_mode[rover_move_mode][(uint8_t)Motor::MotorRole::MotorRoleFrontLeft]);
    FR->setMode(rover_movement_mode[rover_move_mode][(uint8_t)Motor::MotorRole::MotorRoleFrontRight]);
    RL->setMode(rover_movement_mode[rover_move_mode][(uint8_t)Motor::MotorRole::MotorRoleRearLeft]);
    RR->setMode(rover_movement_mode[rover_move_mode][(uint8_t)Motor::MotorRole::MotorRoleRearRight]);
}

void Rover::forward()
{
    _setMode(ROVER_MODE_FORWARD);
    printf("Rover moves forward\n");
}

void Rover::backward()
{
    _setMode(ROVER_MODE_BACKWARD);
    printf("Rover moves backward\n");
}

void Rover::leftSideway()
{
    _setMode(ROVER_MODE_LEFT_SIDEWAY);
    printf("Rover moves leftSideway\n");
}

void Rover::rightSideway()
{
    _setMode(ROVER_MODE_RIGHT_SIDEWAY);
    printf("Rover moves rightSideway\n");
}

void Rover::leftDiagonal()
{
    _setMode(ROVER_MODE_LEFT_DIAGONAL);
    printf("Rover moves leftDiagonal\n");
}

void Rover::rightDiagonal()
{
    _setMode(ROVER_MODE_RIGHT_DIAGONAL);
    printf("Rover moves rightDiagonal\n");
}

void Rover::leftConcerning()
{
    _setMode(ROVER_MODE_LEFT_CONCERNING);
    printf("Rover moves leftConcerning\n");
}

void Rover::rightConcerning()
{
    _setMode(ROVER_MODE_RIGHT_CONCERNING);
    printf("Rover moves rightConcerning\n");
}

void Rover::leftTurnround()
{
    _setMode(ROVER_MODE_LEFT_TURNROUND);
    printf("Rover moves leftTurnround\n");

}

void Rover::rightTurnround()
{
    _setMode(ROVER_MODE_RIGHT_TURNROUND);
    printf("Rover moves rightTurnround\n");
}

void Rover::leftTurnFrontAxis()
{
    _setMode(ROVER_MODE_LEFT_TURNFRONTAXIS);
    printf("Rover moves leftTurnFrontAxis\n");
}

void Rover::rightTurnFrontAxis()
{
    _setMode(ROVER_MODE_RIGHT_TURNFRONTAXIS);
    printf("Rover moves rightTurnFrontAxis\n");
}

void Rover::leftTurnRearAxis()
{
    _setMode(ROVER_MODE_LEFT_TURNFREARAXIS);
    printf("Rover moves leftTurnRearAxis\n");
}

void Rover::rightTurnRearAxis()
{
    _setMode(ROVER_MODE_RIGHT_TURNREARAXIS);
    printf("Rover moves rightTurnRearAxis\n");
}

void Rover::stop()
{
    _setMode(ROVER_MODE_STOP);
    printf("Rover stop\n");
}

void Rover::powerOff()
{
    stop();
    printf("Rover powerOff\n");
}

