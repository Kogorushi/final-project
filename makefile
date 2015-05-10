#####################################################
# Programmer:   Luke H Holliday
# Date:         1/31/2015
# Course:       CS 5201
# Purpose:      makefile1 for example source code.
#####################################################

#CXX = /usr/bin/g++
CXX = clang++
CXXFLAGS = -std=c++0x -g -Wall -W -pedantic-errors

OBJECTS = driver.o

.SUFFIXES : .cpp

.cpp.o : $<
	${CXX} -c ${CXXFLAGS} $< -o $@

default : all

all : driver

remake : clean all

driver : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@

clean :
	-@ rm -f core > /dev/null 2>&1
	-@ rm -f driver > /dev/null 2>&1
	-@ rm -f ${OBJECTS} > /dev/null 2>&1

#Dependency Lists

driver.o : driver.cpp vector.h vector.hpp \
           gaussElim.h gaussElim.hpp matrix.h upperTMatrix.h upperTMatrix.hpp \
           matrix.hpp matrixInterface.h matrixFuncs.h matrixFuncs.hpp \
           lowerTMatrix.h lowerTMatrix.hpp
