/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 4
/  DESC:  a header file for a gaussElim functor class that 
/         uses a Gaussian Elimination Algorithm with Scaled Partial Pivoting.
*/

#ifndef GAUSSELIM_H
#define GAUSSELIM_H

#include "matrix.h"
#include "vector.h"
#include <cmath>

template <typename T>
class gaussElim
{
  private:
  //      Desc adds a row of A and b to another row of A and b.
  //Pre:  number of rows in A must match the number of rows in b.  target and rowNum must be
  //      in the range [0, A.getRows())         
  //Post:  Adds rowNum row of A and b, multiplied by scalar, to target row of A and b. 
  void rowAdd(int target, int rowNum, T scalar, matrix<T>& A, vector<T>& b);
  //Desc:  Swaps rows in A and b.
  //Pre:  number of rows in A must match the number of rows in b.  target and rowNum must be
  //      in the range [0, A.getRows())   
  //Post:  Swaps target1 row of A and b with target2 row of A and b.
  void rowSwap(int target1, int target2, matrix<T>& A, vector<T>& b);
  public:
  //Desc:  Performs Gaussian Elimination with scaled partial pivoting on matrix A and vector b.
  //       returns the solution vector x.
  //Pre:  number of rows of A must be equal to the number of rows in b.
  //Post:  Modifies A and b to be in row echelon form.  Returns a vector x
  //       such that for reduced matrix A and reduced vector b, Ax = b.
  vector<T> operator()(matrix<T>& A, vector<T>& b);
};

#include "gaussElim.hpp"

#endif