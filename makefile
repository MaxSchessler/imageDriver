#
# makefile for image utilities C library
#

CC = gcc
FLAGS = -Wall --std=gnu99 -g
INCLUDES = -lm

.DEFAULT_GOAL := imageDriver

all: imageDriver imageMaker arrayUtilsTester

imageDriver: image_utils.o imageDriver.c
	$(CC) $(FLAGS) image_utils.o imageDriver.c -o imageDriver $(INCLUDES)

imageMaker: image_utils.o imageMaker.c
	$(CC) $(FLAGS) image_utils.o imageMaker.c -o imageMaker $(INCLUDES)

image_utils.o: image_utils.c image_utils.h
	$(CC) $(FLAGS) -c image_utils.c -o image_utils.o $(INCLUDES)

arrayUtilsTester: array_utils.o arrayUtilsTester.c
	$(CC) $(FLAGS) array_utils.o arrayUtilsTester.c -o arrayUtilsTester $(INCLUDES)

array_utils.o: array_utils.c array_utils.h
	$(CC) $(FLAGS) -c array_utils.c -o array_utils.o $(INCLUDES)

clean:
	rm -fR *~ *.o *.dSYM
