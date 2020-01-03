/*

This is the main entry point of Macanum wheel rover application

*/

#include "rover.h"

int main(int argc, char**argv)
{
   BH::Rover rover;
   rover.init();
   rover.forward();
}
