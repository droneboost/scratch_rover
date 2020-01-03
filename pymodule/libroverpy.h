#ifndef __LIBROVERPY_H__
#define __LIBROVERPY_H__

#include <Python.h>

PyObject * init(PyObject *);
PyObject * forward(PyObject *, PyObject *);
PyObject * backward(PyObject *, PyObject *);
PyObject * leftSideway(PyObject *, PyObject *);
PyObject * rightSideway(PyObject *, PyObject *);
PyObject * leftDiagonal(PyObject *, PyObject *);
PyObject * rightDiagonal(PyObject *, PyObject *);
PyObject * leftConcerning(PyObject *, PyObject *);
PyObject * rightConcerning(PyObject *, PyObject *);
PyObject * leftTurnround(PyObject *, PyObject *);
PyObject * rightTurnround(PyObject *, PyObject *);
PyObject * leftTurnFrontAxis(PyObject *, PyObject *);
PyObject * rightTurnFrontAxis(PyObject *, PyObject *);
PyObject * leftTurnRearAxis(PyObject *, PyObject *);
PyObject * rightTurnRearAxis(PyObject *, PyObject *);
PyObject * stop(PyObject *);
PyObject * powerOff(PyObject *);

#endif
