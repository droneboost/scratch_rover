CC = g++
CFLAGS=-c -Wall
LIB = ../../driver/src
INCLUDES = -I ../../driver/include

all: rover

rover: main.o rover.o motor.o pca9685.o gpio.o i2c.o
	$(CC) main.o rover.o motor.o pca9685.o gpio.o i2c.o -o rover
	rm -rf *.o

main.o: main.cpp
	$(CC) $(INCLUDES) $(CFLAGS) main.cpp

rover.o: rover.cpp
	$(CC) $(INCLUDES) $(CFLAGS) rover.cpp

motor.o: motor.cpp
	$(CC) $(INCLUDES) $(CFLAGS) motor.cpp

pca9685.o: $(LIB)/pca9685.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(LIB)/pca9685.cpp

gpio.o: $(LIB)/gpio.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(LIB)/gpio.cpp

i2c.o: $(LIB)/i2c.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(LIB)/i2c.cpp

clean:
	rm -rf *.o rover
