#include "libroverpy.h"

char hellofunc_docs[] = "Rover description.";
char heymanfunc_docs[] = "Echo your name and passed number.";
char addfunc_docs[] = "Add two numbers function.";

PyMethodDef rover_funcs[] = {
	{	"init",
		(PyCFunction)init,
		METH_NOARGS,
		hellofunc_docs},
	{	"heyman",
		(PyCFunction)heyman,
		METH_VARARGS,
		heymanfunc_docs},
	{	"add",
		(PyCFunction)add,
		METH_VARARGS,
		addfunc_docs},

	{	NULL}
};

char rovermod_docs[] = "This is rover module.";

PyModuleDef rover_mod = {
	PyModuleDef_HEAD_INIT,
	"rover",
	rovermod_docs,
	-1,
	rover_funcs,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC PyInit_rover(void) {
	return PyModule_Create(&rover_mod);
}
