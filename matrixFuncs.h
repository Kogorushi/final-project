/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 5
/  DESC:  A header file for functions that utilize an interface class called matrixInt.
*/

#ifndef MATRIX_FUNCS_H
#define MATRIX_FUNCS_H
#include "matrixInterface.h"
#include "matrix.h"



//Desc:  This monstrosity is designed to make matrix addition take fewer opperations
//       when working with special matrices.  It adds 2 matrices together and returns
//       a dense matrix of the addition.
//Pre:   the number of columns and rows must be the same between the two matrices you are adding.
//       Addition and assignment operators must be defined for objects of type T.
//Post:  Returns a matrix, retVal, such that every element in retVal is equal to its corresponding
//       elements in lhs and rhs added together.
template<typename T>
matrix<T> operator+(const matrixInt<T>& lhs, const matrixInt<T>& rhs);

//Desc:  This is designed to make matrix subtraction take fewer opperations
//       when working with special matrices and be compatible with all matrices.
//       It adds 2 matrices together and returns a dense matrix of the subtraction.
//Pre:   the number of columns and rows must be the same between the two matrices you are subtracting.
//       Subtraction and assignment operators must be defined for objects of type T.
//Post:  Returns a matrix, retVal, such that every element in retVal is equal to its corresponding
//       elements in lhs subtracted from its corresponding element in rhs.
template <typename T>
matrix<T> operator-(const matrixInt<T>& lhs, const matrixInt<T>& rhs);

//Desc:  This is designed to make matrix multiplication take fewer opperations
//       when working with special matrices.  It multiplies 2 matrices together and returns
//       a dense matrix of the multiplication.
//Pre:   the number of columns in lhs must match the number of rows in rhs.  assignment, addition
//       and multiplication must be defined for objects of type T.
//Post:  Returns a matrix, retVal, equal to the multiplication of the matrices lhs and rhs.
template<typename T>
matrix<T> operator*(const matrixInt<T>& lhs, const matrixInt<T>& rhs);

//Desc:  This is designed to make matrix multiplication by a scalar take fewer opperations
//       when working with special matrices.  It multiplies a matrix by a scalar and returns
//       a dense matrix of the multiplication.
//Pre:   multiplication and assignment must be defined for objects of type T.
//Post:  Returns a matrix, retVal, such that every element in retVal is equal to its corresponding
//       element in lhs multiplied by scalar rhs.
template<typename T>
matrix<T> operator*(const matrixInt<T>& lhs, const T rhs);

//Desc:  Stream opperator for all matrix classes derived from the matrixInt interface.
//Pre:  lhs must be open and good.
//Post:  writes matrix c to stream and returns a reference to stream.     
template<typename T>
ostream& operator<<(ostream& stream, const matrixInt<T>& c);

//Desc:  Reads a matrix from stream and inputs it into a matrix of type derived from
//       matrixInt.  Stream must be formatted as a full matrix (including 0s).
//Pre:   stream must be open, good, and properly formatted.
//Post:  reads from stream and writes the values of stream to the matrix c.
template<typename T>
istream& operator>>(istream& stream, matrixInt<T>& c);


#include "matrixFuncs.hpp"
#endif