#include <stdio.h>
#include <Python.h>
#include "libroverpy.h"
#include "rover.h"

using namespace BH;
namespace {
    Rover rover;
}

/*
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
*/

PyObject* init(PyObject* self)
{
    rover.init();
    return PyUnicode_FromFormat("Rover is init!");
}

PyObject* deinit(PyObject* self)
{
    rover.deinit();
    return PyUnicode_FromFormat("Rover is deinit!");
}

PyObject* forward(PyObject* self)
{
    rover.forward();
    return PyUnicode_FromFormat("Rover moves forward!");
}

PyObject* backward(PyObject* self)
{
    rover.backward();
    return PyUnicode_FromFormat("Rover moves backward!");
}

PyObject* leftSideway(PyObject* self)
{
    rover.leftSideway();
    return PyUnicode_FromFormat("Rover moves leftSideway!");
}

PyObject* rightSideway(PyObject* self)
{
    rover.leftSideway();
    return PyUnicode_FromFormat("Rover moves rightSideway!");
}

PyObject* leftDiagonal(PyObject* self)
{
    rover.leftDiagonal();
    return PyUnicode_FromFormat("Rover moves leftDiagonal!");
}

PyObject* rightDiagonal(PyObject* self)
{
    rover.rightDiagonal();
    return PyUnicode_FromFormat("Rover moves rightDiagonal!");
}

PyObject* leftConcerning(PyObject* self)
{
    rover.leftConcerning();
    return PyUnicode_FromFormat("Rover moves leftConcerning!");
}

PyObject* rightConcerning(PyObject* self)
{
    rover.rightConcerning();
    return PyUnicode_FromFormat("Rover moves rightConcerning!");
}

PyObject* leftTurnround(PyObject* self)
{
    rover.leftTurnround();
    return PyUnicode_FromFormat("Rover moves leftTurnround!");
}

PyObject* rightTurnround(PyObject* self)
{
    rover.rightTurnround();
    return PyUnicode_FromFormat("Rover moves rightTurnround!");
}

PyObject* leftTurnFrontAxis(PyObject* self)
{
    rover.leftTurnFrontAxis();
    return PyUnicode_FromFormat("Rover moves leftTurnFrontAxis!");
}

PyObject* rightTurnFrontAxis(PyObject* self)
{
    rover.rightTurnFrontAxis();
    return PyUnicode_FromFormat("Rover moves rightTurnFrontAxis!");
}

PyObject* leftTurnRearAxis(PyObject* self)
{
    rover.leftTurnRearAxis();
    return PyUnicode_FromFormat("Rover moves leftTurnRearAxis!");
}

PyObject* rightTurnRearAxis(PyObject* self)
{
    rover.rightTurnRearAxis();
    return PyUnicode_FromFormat("Rover moves rightTurnRearAxis!");
}

PyObject* stop(PyObject* self)
{
    rover.stop();
    return PyUnicode_FromFormat("Rover stop!");
}

PyObject* powerOff(PyObject* self)
{
    rover.powerOff();
    return PyUnicode_FromFormat("Rover powerOff!");
}

PyObject* setFrontLeftSpeed(PyObject* self, PyObject* args)
{
    int speed = 0;

    if(!PyArg_ParseTuple(args, "i", &speed))
        return NULL;

    rover.setFrontLeftSpeed(speed);
    return PyUnicode_FromFormat("Rover setFrontLeftSpeed!");
}                           

PyObject* setFrontRightSpeed(PyObject* self, PyObject* args)
{
    int speed = 0;

    if(!PyArg_ParseTuple(args, "i", &speed))
        return NULL;

    rover.setFrontRightSpeed(speed);
    return PyUnicode_FromFormat("Rover setFrontRightSpeed!");
}

PyObject* setRearLeftSpeed(PyObject* self, PyObject* args)
{
    int speed = 0;

    if(!PyArg_ParseTuple(args, "i", &speed))
        return NULL;

    rover.setRearLeftSpeed(speed);
    return PyUnicode_FromFormat("Rover setRearLeftSpeed!");
}

PyObject* setRearRightSpeed(PyObject* self, PyObject* args)
{
   int speed = 0;

    if(!PyArg_ParseTuple(args, "i", &speed))
        return NULL;                                

    rover.setRearRightSpeed(speed);
    return PyUnicode_FromFormat("Rover setRearRightSpeed!");
}

PyObject* setFrontSpeed(PyObject* self, PyObject* args)
{
    int speedL = 0;
    int speedR = 0;

    if(!PyArg_ParseTuple(args, "ii", &speedL, &speedR))
        return NULL;                                

    rover.setFrontSpeed(speedL, speedR);
    return PyUnicode_FromFormat("Rover setFrontSpeed!");

}

PyObject* setRearSpeed(PyObject* self, PyObject* args)
{
    int speedL = 0;
    int speedR = 0;

    if(!PyArg_ParseTuple(args, "ii", &speedL, &speedR))
        return NULL;                                

    rover.setRearSpeed(speedL, speedR);
    return PyUnicode_FromFormat("Rover setRearSpeed!");
}

PyObject* setSpeed(PyObject* self, PyObject* args)
{
    int speedFL = 0;
    int speedFR = 0;
    int speedRL = 0;
    int speedRR = 0;

    if(!PyArg_ParseTuple(args, "iiii", &speedFL, &speedFR, &speedRL, &speedRR))
        return NULL;                                

    rover.setSpeed(speedFL, speedFR, speedRL, speedRR);
    return PyUnicode_FromFormat("Rover setSpeed!");
}
