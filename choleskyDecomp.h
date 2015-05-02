/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 6
/  DESC:  a header file for cholesky functions that acts
*/

#ifndef CHOLESKY_DECOMP_H
#define CHOLESKY_DECOMP_H

#include <cmath>

/*  Pre:  A.getRows()*A.getCols() >= 1.  Objects of type T must be assignable to 0.
//        Requires assignment, subtraction, addition, multiplication, and division of objects of type T.
//  Post: returns a lowerTMatrix equivalent to the cholesky decomposition of A.
*/
template <typename T>
lowerTMatrix<T> cholesky(symmetricMatrix<T>& A);

/*  Pre:  A.getRows()*A.getCols() >= 1.  Objects of type T must be assignable to 0.
//        Requires assignment, subtraction, addition, multiplication, and division of objects of type T.
//        A.getRows() == A.getCols() == b.getRows().
//  Post: returns a vector x that is the solution to the cholesky decomposition of A for b.
*/
template <typename T>
vector<T> choleskySolver(const lowerTMatrix<T>& A, const vector<T>& b);

#include "choleskyDecomp.hpp"
#endif