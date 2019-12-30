#include <stdio.h>
#include <Python.h>
#include "libroverpy.h"
#include "motor.h"
#include "gpio.h"
#include "pca9685.h"
#include "motor.h"

using namespace BH;
namespace {
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

PyObject * init(PyObject * self) {
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

    FL.init();
    FR.init();
    RL.init();
    RR.init();
    FL.setSpeed(1500);
    FR.setSpeed(1500);
    RL.setSpeed(1500);
    RR.setSpeed(1500);
    printf("Rover is initalized!\n");
    return PyUnicode_FromFormat("Rover is initalized!");
}

PyObject * heyman(PyObject *self, PyObject *args) {
    int num;
    char *name;

    if(!PyArg_ParseTuple(args, "is", &num, &name))
        return NULL;

    return PyUnicode_FromFormat("Hay %s!  You gave me %d.", name, num);
}

PyObject * add(PyObject *self, PyObject *args) {
	int num1, num2;
	char eq[20];

	if(!PyArg_ParseTuple(args, "ii", &num1, &num2))
		return NULL;

	sprintf(eq, "%d + %d", num1, num2);

	return Py_BuildValue("is", num1 + num2, eq);
}

PyObject * forward(PyObject *, PyObject *) {
    FL.forward();
    FR.forward();
    RL.forward();
    RR.forward();
}
PyObject * backward(PyObject *, PyObject *);
PyObject * leftsideway(PyObject *, PyObject *);
PyObject * rightsideway(PyObject *, PyObject *);
PyObject * diagonal(PyObject *, PyObject *);
PyObject * concerning(PyObject *, PyObject *);
PyObject * turnround(PyObject *, PyObject *);
PyObject * turnfrontaxis(PyObject *, PyObject *);
PyObject * turnrearaxis(PyObject *, PyObject *);
PyObject * stop(PyObject *);
PyObject * poweroff(PyObject *);
