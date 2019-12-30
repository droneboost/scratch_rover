#ifndef MOTOR_H_
#define MOTOR_H_

#include <stdint.h>

#include "gpio.h"
#include "pca9685.h"

namespace BH {

class Motor {
public:
    typedef enum {
        MotorModeForward,
        MotorModeBackward,
        MotorModeStop
    } MotorMode;

    typedef enum {
        MotorRoleFrontLeft,
        MotorRoleFrontRight,
        MotorRoleRearLeft,
        MotorRoleRearRight
    } MotorRole;

    Motor(Pin& a, Pin& b, PCA9685& pwm, uint8_t pwm_chn, MotorRole role);
    ~Motor();

    bool    init();

    void    forward();
    void    backward();
    void    stop();
    void    toggle(); // Forward=>Stop=>Backward or Backward=>Stop=>Forward, do nothing if in Stop Mode
    void    setSpeed(uint32_t speed);

    MotorMode    mode();
    MotorRole    role();
    uint32_t     speed();

private:
    Motor (const Motor&);
    Motor& operator=(const Motor&);

    Pin&       _apin;
    Pin&       _bpin;

    PCA9685&   _pwm;
    uint8_t    _pwm_chn;
    uint32_t   _speed;

    MotorMode  _mode;
    MotorRole  _role;

    void    _setMode(MotorMode mode);
    void    _setRole(MotorRole role);

    bool       _isinit;
};

}
#endif
