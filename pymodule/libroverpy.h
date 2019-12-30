#ifndef __LIBROVERPY_H__
#define __LIBROVERPY_H__

#include <Python.h>

PyObject * heyman(PyObject *, PyObject *);
PyObject * add(PyObject *, PyObject *);

PyObject * init(PyObject *);
PyObject * forward(PyObject *, PyObject *);
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

#endif
