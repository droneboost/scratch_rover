#include "libroverpy.h"

char func_init_docs[]               = "Rover init() function";
char func_forward_docs[]            = "Rover forward() function";
char func_backward_docs[]           = "Rover backward() function";
char func_leftSideway_docs[]        = "Rover leftSideway() function";
char func_rightSideway_docs[]       = "Rover rightSideway() function";
char func_leftDiagonal_docs[]       = "Rover leftDiagonal() function";
char func_rightDiagonal_docs[]      = "Rover rightDiagonal() function";
char func_leftConcerning_docs[]     = "Rover leftConcerning() function";
char func_rightConcerning_docs[]    = "Rover rightConcerning() function";
char func_leftTurnround_docs[]      = "Rover leftTurnround() function";
char func_rightTurnround_docs[]     = "Rover rightTurnround() function";
char func_leftTurnFrontAxis_docs[]  = "Rover leftTurnFrontAxis() function";
char func_rightTurnFrontAxis_docs[] = "Rover rightTurnFrontAxis() function";
char func_leftTurnRearAxis_docs[]   = "Rover leftTurnRearAxis() function";
char func_rightTurnRearAxis_docs[]  = "Rover rightTurnRearAxis() function";
char func_stop_docs[]               = "Rover stop() function";
char func_powerOff_docs[]           = "Rover powerOff() function";

PyMethodDef rover_funcs_table[] = {
	{"init",               (PyCFunction)init,               METH_NOARGS,  func_init_docs},
	{"forward",            (PyCFunction)forward,            METH_NOARGS,  func_forward_docs},
	{"backward",           (PyCFunction)backward,           METH_NOARGS,  func_backward_docs},
	{"leftSideway",        (PyCFunction)leftSideway,        METH_NOARGS,  func_leftSideway_docs},
	{"rightSideway",       (PyCFunction)rightSideway,       METH_NOARGS,  func_rightSideway_docs},
	{"leftDiagonal",       (PyCFunction)leftDiagonal,       METH_NOARGS,  func_leftDiagonal_docs},
	{"rightDiagonal",      (PyCFunction)rightDiagonal,      METH_NOARGS,  func_rightDiagonal_docs},
	{"leftConcerning",     (PyCFunction)leftConcerning,     METH_NOARGS,  func_leftConcerning_docs},
	{"rightConcerning",    (PyCFunction)rightConcerning,    METH_NOARGS,  func_rightConcerning_docs},
	{"leftTurnround",      (PyCFunction)leftTurnround,      METH_NOARGS,  func_leftTurnround_docs},
	{"rightTurnround",     (PyCFunction)rightTurnround,     METH_NOARGS,  func_rightTurnround_docs},
	{"leftTurnFrontAxis",  (PyCFunction)leftTurnFrontAxis,  METH_NOARGS,  func_leftTurnFrontAxis_docs},
	{"rightTurnFrontAxis", (PyCFunction)rightTurnFrontAxis, METH_NOARGS,  func_rightTurnFrontAxis_docs},
	{"leftTurnRearAxis",   (PyCFunction)leftTurnRearAxis,   METH_NOARGS,  func_leftTurnRearAxis_docs},
	{"rightTurnRearAxis",  (PyCFunction)rightTurnRearAxis,  METH_NOARGS,  func_rightTurnRearAxis_docs},
	{"stop",               (PyCFunction)stop,               METH_NOARGS,  func_stop_docs},
	{"powerOff",           (PyCFunction)powerOff,           METH_NOARGS,  func_powerOff_docs},
	{NULL}
};

char rover_mod_docs[] = "This is a rover module.";

PyModuleDef rover_mod = {
	PyModuleDef_HEAD_INIT,
	"rover",
	rover_mod_docs,
	-1,
	rover_funcs_table,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC PyInit_rover(void) {
	return PyModule_Create(&rover_mod);
}
