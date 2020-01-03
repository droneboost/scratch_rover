#include <stdio.h>
#include <Python.h>
#include "libroverpy.h"
#include "rover.h"

using namespace BH;
namespace {
    Rover rover;
}

PyObject * init(PyObject * self)
{
    rover.init();
    return PyUnicode_FromFormat("Rover is initalized!");
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
PyObject * forward(PyObject *, PyObject *)
{
    rover.forward();
}

PyObject * backward(PyObject *, PyObject *)
{
    rover.backward();
}

PyObject * leftSideway(PyObject *, PyObject *)
{
    rover.leftSideway();
}

PyObject * rightSideway(PyObject *, PyObject *)
{
    rover.leftSideway();
}

PyObject * leftDiagonal(PyObject *, PyObject *)
{
    rover.leftDiagonal();
}

PyObject * rightDiagonal(PyObject *, PyObject *)
{
    rover.rightDiagonal();
}

PyObject * leftConcerning(PyObject *, PyObject *)
{
    rover.leftConcerning();
}

PyObject * rightConcerning(PyObject *, PyObject *)
{
    rover.rightConcerning();
}

PyObject * leftTurnround(PyObject *, PyObject *)
{
    rover.leftTurnround();
}

PyObject * rightTurnround(PyObject *, PyObject *)
{
    rover.rightTurnround();
}

PyObject * leftTurnFrontAxis(PyObject *, PyObject *)
{
    rover.leftTurnFrontAxis();
}

PyObject * rightTurnFrontAxis(PyObject *, PyObject *)
{
    rover.rightTurnFrontAxis();
}

PyObject * leftTurnRearAxis(PyObject *, PyObject *)
{
    rover.leftTurnRearAxis();
}

PyObject * rightTurnRearAxis(PyObject *, PyObject *)
{
    rover.rightTurnRearAxis();
}

PyObject * stop(PyObject *)
{
    rover.stop();
}

PyObject * powerOff(PyObject *)
{
    rover.powerOff();
}
