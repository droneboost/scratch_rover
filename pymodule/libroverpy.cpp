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

PyObject * init(PyObject * self)
{
    rover.init();
    return PyUnicode_FromFormat("Rover is init!");
}

PyObject * deinit(PyObject * self)
{
    rover.deinit();
    return PyUnicode_FromFormat("Rover is deinit!");
}

PyObject * forward(PyObject *, PyObject *)
{
    rover.forward();
    return PyUnicode_FromFormat("Rover moves forward!");
}

PyObject * backward(PyObject *, PyObject *)
{
    rover.backward();
    return PyUnicode_FromFormat("Rover moves backward!");
}

PyObject * leftSideway(PyObject *, PyObject *)
{
    rover.leftSideway();
    return PyUnicode_FromFormat("Rover moves leftSideway!");
}

PyObject * rightSideway(PyObject *, PyObject *)
{
    rover.leftSideway();
    return PyUnicode_FromFormat("Rover moves rightSideway!");
}

PyObject * leftDiagonal(PyObject *, PyObject *)
{
    rover.leftDiagonal();
    return PyUnicode_FromFormat("Rover moves leftDiagonal!");
}

PyObject * rightDiagonal(PyObject *, PyObject *)
{
    rover.rightDiagonal();
    return PyUnicode_FromFormat("Rover moves rightDiagonal!");
}

PyObject * leftConcerning(PyObject *, PyObject *)
{
    rover.leftConcerning();
    return PyUnicode_FromFormat("Rover moves leftConcerning!");
}

PyObject * rightConcerning(PyObject *, PyObject *)
{
    rover.rightConcerning();
    return PyUnicode_FromFormat("Rover moves rightConcerning!");
}

PyObject * leftTurnround(PyObject *, PyObject *)
{
    rover.leftTurnround();
    return PyUnicode_FromFormat("Rover moves leftTurnround!");
}

PyObject * rightTurnround(PyObject *, PyObject *)
{
    rover.rightTurnround();
    return PyUnicode_FromFormat("Rover moves rightTurnround!");
}

PyObject * leftTurnFrontAxis(PyObject *, PyObject *)
{
    rover.leftTurnFrontAxis();
    return PyUnicode_FromFormat("Rover moves leftTurnFrontAxis!");
}

PyObject * rightTurnFrontAxis(PyObject *, PyObject *)
{
    rover.rightTurnFrontAxis();
    return PyUnicode_FromFormat("Rover moves rightTurnFrontAxis!");
}

PyObject * leftTurnRearAxis(PyObject *, PyObject *)
{
    rover.leftTurnRearAxis();
    return PyUnicode_FromFormat("Rover moves leftTurnRearAxis!");
}

PyObject * rightTurnRearAxis(PyObject *, PyObject *)
{
    rover.rightTurnRearAxis();
    return PyUnicode_FromFormat("Rover moves rightTurnRearAxis!");
}

PyObject * stop(PyObject *)
{
    rover.stop();
    return PyUnicode_FromFormat("Rover stop!");
}

PyObject * powerOff(PyObject *)
{
    rover.powerOff();
    return PyUnicode_FromFormat("Rover powerOff!");
}
