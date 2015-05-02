/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 4
/  DESC:  a header file for a thomas Algorithm that solves Ax = d
/         where A is a tridiagonal matrix.
*/




#ifndef THOMAS_ALGORITHM_H
#define THOMAS_ALGORITHM_H

//  Pre:  A.getRows()*A.getCols() >= 1.  A.getCols() == d.getRows().
//  Post:  returns the vector solution for Ax = d
template <typename T>
vector<T> thomasAlgorithm(tridiagonalMatrix<T>& A, vector<T>& d);

#include "thomasAlgorithm.hpp"

#endif