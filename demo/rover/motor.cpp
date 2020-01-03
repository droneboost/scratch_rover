#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "motor.h"

using namespace BH;


namespace {
    static const uint MOTOR_DEFAULT_SPEED = 1500;
}

Motor::Motor(Pin& a, Pin& b, PCA9685& pwm, uint8_t pwm_chn, MotorRole role)
            :_apin(a), _bpin(b), _pwm(pwm), _pwm_chn(pwm_chn), _role(role)
{
    _mode = MotorModeStop;
    _speed = MOTOR_DEFAULT_SPEED;
    _isinit = false;
}

Motor::~Motor()
{
    _setMode(MotorModeStop);
}

bool Motor::init()
{
//    if(_isinit == true) return true;

    if (!_apin.init()) {
        printf("Motor %d A Pin init error. Are you root\n", _role);
        return false;
    }
    _apin.setMode(Pin::GpioModeOutput);
    _apin.write(0);

    if (!_bpin.init()) {
        printf("Motor %d b Pin init error. Are you root\n", _role);
        return false;
    }
    _bpin.setMode(Pin::GpioModeOutput);
    _bpin.write(0);

    setSpeed(0);

    _isinit = true;
    printf("Motor %d inited\n", _role);
    return _isinit;
}

void Motor::forward()
{
    _setMode(MotorModeForward);
}

void Motor::backward()
{
    _setMode(MotorModeBackward);
}

void Motor::stop()
{
    _setMode(MotorModeStop);
}

void Motor::setMode(MotorMode mode)
{
     _setMode(mode);
}

void Motor::toggle()
{
//    if(_isinit == true && _mode == MotorModeStop) return;

    _setMode(MotorModeStop);
    sleep(1);

    if(_mode == MotorModeForward) {
        _setMode(MotorModeBackward);
        printf("Motor %d toggle from Forward to Backward\n", _role);
    } else {
        _setMode(MotorModeForward);
        printf("Motor %d toggle from Backward to Forward\n", _role);
    }
}

void Motor::setSpeed(uint32_t speed)
{
//    if(_isinit == true && _speed == speed) return;

     _speed = speed;
    _pwm.setPWM(_pwm_chn, 0, _speed);
    printf("Motor %d set speed %d\n", _role, _speed);
}

Motor::MotorMode Motor::mode()
{
    return _mode;
}

Motor::MotorRole Motor::role()
{
    return _role;
}

uint32_t Motor::speed()
{
    return _speed;
}

void Motor::_setMode(MotorMode mode)
{
//    if(_isinit == true && _mode == mode) return;

    _mode = mode;

    _pwm.setPWM(_pwm_chn, 0, 0);
    switch (_mode) {
    case MotorModeForward:
//        if(_role == MotorRoleFrontLeft || _role == MotorRoleRearRight) {
            _apin.write(0);
            _bpin.write(1);
//        } else if (_role == MotorRoleFrontRight || _role == MotorRoleRearLeft) {
//            _apin.write(1);
//           _bpin.write(0);
//        }
        _pwm.setPWM(_pwm_chn, 0, _speed);
        printf("Motor %d set in Forward\n", _role);
        break;

    case MotorModeBackward:
//       if(_role == MotorRoleFrontLeft || _role == MotorRoleRearRight) {
            _apin.write(1);
            _bpin.write(0);
//        } else if (_role == MotorRoleFrontRight || _role == MotorRoleRearLeft) {
//            _apin.write(0);
//            _bpin.write(1);
//        }
        _pwm.setPWM(_pwm_chn, 0, _speed);
        printf("Motor %d set in Backward\n", _role);
        break;

    case MotorModeStop:
    default:
        _pwm.setPWM(_pwm_chn, 0, 0);
        _apin.write(0);
        _bpin.write(0);
        printf("Motor %d set in Stop mode\n", _role);
        break;
    }
}

void Motor::_setRole(MotorRole role)
{
    _role = role;
}
