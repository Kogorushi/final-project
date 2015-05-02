/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 5
/  DESC:  a header file for a lowerTMatrix class that acts
/         like a mathematical matrix.
*/

#ifndef LOWER_T_MATRIX_H
#define LOWER_T_MATRIX_H
#include "matrixInterface.h"

template <typename T>
class lowerTMatrix : public virtual matrixInt<T>
{
  private:
  T* m_Matrix;
  int m_numRows;
  int m_numCols;
  int m_flg;

  public:
  //Constructor/Destructors
  //Pre:  none.
  //Post:  initializes m_numRows and m_numCols to 0 and m_flg to 110.
  lowerTMatrix();
  //Pre: none;  r and c should be greater than 0, but it isn't necessary.
  //Post:  If row > 0 and col > 0, initializes m_Matrix to be a new array of size row*col
  //       and sets each value in m_Matrix to 0.
  //       Otherwise, sets m_numRows and m_numCols to 0.  Also, sets m_flg to 110.
  lowerTMatrix(int r, int c);
  //Pre:  none.
  //Post:  If reference to matrixInt x does not reference *this, overwrites the current
  //       object, *this, to be a deep copy of the upper right part of x. (can be used to copy
  //       a full matrix into an lowerTMatrix)
  lowerTMatrix(matrixInt<T>& x);
  //Pre:  none.
  //Post:  If reference to matrixInt x does not reference *this, overwrites the current
  //       object, *this, to be a deep copy of the upper right part of x. (can be used to copy
  //       a full matrix into an lowerTMatrix)
  lowerTMatrix(lowerTMatrix<T>& x);
  //Pre:  none.
  //Post:  if m_numRows > 0 and m_numCols > 0, deletes m_Matrix and sets m_numRows = m_numCols = 0.
  ~lowerTMatrix();

  //ACCESSORS
  //Pre:  0 < row =< m_numRows and 0 < col =< m_numCols.
  //Post:  returns a modifiable reference to element T at the specified row and column.
  virtual T& operator()(const int row, const int col);
  //Pre:  0 < row =< m_numRows and 0 < col =< m_numCols.
  //Post:  returns an unmodifiable reference to element T at the specified row and column.
  virtual const T& operator()(const int row, const int col) const;
  //Pre:  none.
  //Post:  returns an unmodifiable reference to m_numCols.
  virtual int getCols() const;
  //Pre:  none.
  //Post:  returns an unmodifiable reference to m_numRows.
  virtual int getRows() const;
  //Pre:  none.
  //Post:  returns the value of m_flg.
  virtual int getFlg() const;
  //Pre:   assignment must be defined for objects of type T.
  //Post:  if reference to maatrixInt x does not reference *this matrix, overwrite this object
  //       to be a deep copy of x.  Returns a reference to this object.
  lowerTMatrix& operator=(const matrixInt<T>&);
  //Pre:   assignment must be defined for objects of type T.
  //Post:  if reference to maatrixInt x does not reference *this matrix, overwrite this object
  //       to be a deep copy of x.  Returns a reference to this object.
  lowerTMatrix& operator=(const lowerTMatrix<T>&);
  //Pre:   assignment and default construction must be defined for objects of type T.
  //       Objects of type T must be assignable to 0.
  //Post:  If row > 0 and col > 0 and row*col differs from m_numRows*m_numCols,
  //       deletes m_Matrix and creates a new m_Matrix of size row*col and set m_numRows = row and
  //       m_numCols = col.  If row or col are less than 1 and m_numRows > 0, delete m_Matrix.  
  //       Then, if row > 0 and col > 0, initializes the values of m_Matrix to 0.
  //       Otherwise, sets m_numRows = n_numCols = 0.  Returns a reference to this object.
  lowerTMatrix& buildNew(const int row, const int col);
};

#include "lowerTMatrix.hpp"
#endif