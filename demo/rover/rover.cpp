/*

This is the main entry point of Macanum wheel rover application

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "gpio.h"
#include "pca9685.h"
#include "motor.h"

using namespace BH;

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

int main(int argc, char**argv)
{
    Pin pin1(INT1);  Pin pin2(INT2); // Pin init inside Motor class init()
    Pin pin3(INT3);  Pin pin4(INT4);
    Pin pin5(INT5);  Pin pin6(INT6);
    Pin pin7(INT7);  Pin pin8(INT8);

    Pin pwm_en_pin(PWM_EN_PIN);
    if (!pwm_en_pin.init()) {
        printf("Motor PWM Enable pin not set. Are you root\n");
        return 0;
    }
    pwm_en_pin.setMode(Pin::GpioModeOutput);
    pwm_en_pin.write(0); /* drive Output Enable low */

    PCA9685 pwm;
    if (!pwm.init()) {
        printf("Motor PWM init failed. Are you root\n");
        return 0;
    }
 
    pwm.setFrequency(100);
    printf("Motor PWM set frequency %f\n", pwm.getFrequency());


    Motor FL(pin1, pin2, pwm, ENA, Motor::MotorRoleFrontLeft);
    Motor FR(pin3, pin4, pwm, ENB, Motor::MotorRoleFrontRight);
    Motor RL(pin5, pin6, pwm, ENC, Motor::MotorRoleRearLeft);
    Motor RR(pin7, pin8, pwm, END, Motor::MotorRoleRearRight);

//    Motor FL(pin1, pin2, pwm, ENA, Motor::MotorRoleFrontLeft);
//    Motor RR(pin3, pin4, pwm, ENB, Motor::MotorRoleFrontRight);
//    Motor RL(pin5, pin6, pwm, ENC, Motor::MotorRoleRearLeft);
//    Motor FR(pin7, pin8, pwm, END, Motor::MotorRoleRearRight);

    FL.init();
    FR.init();
    RL.init();
    RR.init();
    FL.setSpeed(1500);
    FR.setSpeed(1500);
    RL.setSpeed(1500);
    RR.setSpeed(1500);

//    sleep(1);

    printf("pin1 current value: %d\n", pin1.read());
    printf("pin2 current value: %d\n", pin2.read());
    printf("pin3 current value: %d\n", pin3.read());
    printf("pin4 current value: %d\n", pin4.read());
    printf("pin5 current value: %d\n", pin5.read());
    printf("pin6 current value: %d\n", pin6.read());
    printf("pin7 current value: %d\n", pin7.read());
    printf("pin8 current value: %d\n", pin8.read());


//    FL.setSpeed(1000);

//    FL.forward(); //correct
//    FR.forward();
//    RL.forward(); //correct
//    RR.forward();


//    FL.backward();
//    FR.backward();
//    RL.backward();
//    RR.backward();

    FL.forward();
    FR.forward();
    RL.forward();
    RR.forward();
//    FL.forward();


    while(1) {
      sleep(2);
      printf("pin1 current value: %d\n", pin1.read());
      printf("pin2 current value: %d\n", pin2.read());
      printf("pin3 current value: %d\n", pin3.read());
      printf("pin4 current value: %d\n", pin4.read());
      printf("pin5 current value: %d\n", pin5.read());
      printf("pin6 current value: %d\n", pin6.read());
      printf("pin7 current value: %d\n", pin7.read());
      printf("pin8 current value: %d\n", pin8.read());
    }

    return 1;
}
