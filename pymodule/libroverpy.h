#ifndef __LIBROVERPY_H__
#define __LIBROVERPY_H__

#include <Python.h>

PyObject * init(PyObject *);
PyObject * deinit(PyObject *);
PyObject * forward(PyObject *);
PyObject * backward(PyObject *);
PyObject * leftSideway(PyObject *);
PyObject * rightSideway(PyObject *);
PyObject * leftDiagonal(PyObject *);
PyObject * rightDiagonal(PyObject *);
PyObject * leftConcerning(PyObject *);
PyObject * rightConcerning(PyObject *);
PyObject * leftTurnround(PyObject *);
PyObject * rightTurnround(PyObject *);
PyObject * leftTurnFrontAxis(PyObject *);
PyObject * rightTurnFrontAxis(PyObject *);
PyObject * leftTurnRearAxis(PyObject *);
PyObject * rightTurnRearAxis(PyObject *);
PyObject * stop(PyObject *);
PyObject * powerOff(PyObject *);
PyObject * setFrontLeftSpeed(PyObject *, PyObject *);
PyObject * setFrontRightSpeed(PyObject *, PyObject *);
PyObject * setRearLeftSpeed(PyObject *, PyObject *);
PyObject * setRearRightSpeed(PyObject *, PyObject *);
PyObject * setFrontSpeed(PyObject *, PyObject *);
PyObject * setRearSpeed(PyObject *, PyObject *);
PyObject * setSpeed(PyObject *, PyObject *);

#endif
