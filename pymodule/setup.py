#!/usr/bin/env python3

from distutils.core import setup, Extension

setup(
	name = "rover",
	version = "1.0",
	ext_modules = [Extension("rover",
                                 language = "c++",
                                 extra_compile_args = ['-std=c++11'],
                                 include_dirs = ['../demo/rover',
                                                 '../driver/include'],
                                 sources=['bind.cpp',
                                          'libroverpy.cpp',
                                          '../demo/rover/rover.cpp',
                                          '../demo/rover/motor.cpp',
                                          '../driver/src/gpio.cpp',
                                          '../driver/src/i2c.cpp',
                                          '../driver/src/pca9685.cpp'])]
);
