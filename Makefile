# Structured makefile for camera placement
#
#
CC = g++
cflag = -DMATRIX
LDLIBS =  -lglut -lGL -lGLU -lm
HEADERS = opengl.h structs.h globals.h constants.h prototypes.h
OBJS = init.o defineBox.o drawBox.o drawAxes.o reshape.o display.o 
CFLAGS = -O
all: viewp tags 

viewp :	main.o $(OBJS) 
	$(CC) $(CFLAGS) main.o $(OBJS) -o viewp $(LDLIBS)

main.o : main.cc $(HEADERS)
	$(CC) $(CFLAGS) main.cc -c

init.o : init.cc $(HEADERS)
	$(CC) $(CFLAGS) init.cc -c

defineBox.o : defineBox.cc $(HEADERS)
	$(CC) $(CFLAGS) defineBox.cc -c

drawBox.o : drawBox.cc $(HEADERS)
	$(CC) $(CFLAGS) drawBox.cc -c

drawAxes.o : drawAxes.cc $(HEADERS)
	$(CC) $(CFLAGS) drawAxes.cc -c

reshape.o : reshape.cc $(HEADERS)
	$(CC) $(cflag) $(CFLAGS) reshape.cc -c

display.o : display.cc $(HEADERS)
	$(CC) $(CFLAGS) display.cc -c
clean:
	rm *.o
	rm viewp
pristine:
	rm *.o
	touch *

tags:
	ctags *.h *.cc
