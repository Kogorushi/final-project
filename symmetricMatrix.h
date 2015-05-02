/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 6
/  DESC:  a header file for a symmetricMatrix class that acts
/         like a mathematical matrix.
*/

#ifndef SYMMETRIC_MATRIX_H
#define SYMMETRIC_MATRIX_H
#include "matrixInterface.h"

template <typename T>
class symmetricMatrix : public virtual matrixInt<T>, public upperTMatrix<T>
{
  public:
  //Constructor/Destructors
  //Pre:  none.
  //Post:  initializes m_numRows and m_numCols to 0 and m_flg to 111.
  symmetricMatrix();
  //Pre: none;  r and c should be greater than 0, but it isn't necessary.
  //Post:  If row > 0 and col > 0, initializes m_Matrix to be a new array of size row*col
  //       and sets each value in m_Matrix to 0.
  //       Otherwise, sets m_numRows and m_numCols to 0.  Also, sets m_flg to 111.
  symmetricMatrix(int r, int c);
  //Pre:  none.
  //Post:  If reference to matrixInt x does not reference *this, overwrites the current
  //       object, *this, to be a deep copy of the upper right part of x. (can be used to copy
  //       a full matrix into an symmetricMatrix)
  symmetricMatrix(matrixInt<T>& x);
  //Pre:  none.
  //Post:  If reference to matrixInt x does not reference *this, overwrites the current
  //       object, *this, to be a deep copy of the upper right part of x. (can be used to copy
  //       a full matrix into an symmetricMatrix)
  symmetricMatrix(symmetricMatrix<T>& x);
  //Pre:  none.
  //Post:  if m_numRows > 0 and m_numCols > 0, deletes m_Matrix and sets m_numRows = m_numCols = 0.
  ~symmetricMatrix();

  //ACCESSORS
  //Pre:  0 < row =< m_numRows and 0 < col =< m_numCols.
  //Post:  returns a modifiable reference to element T at the specified row and column.
  virtual T& operator()(const int row, const int col);
  //Pre:  0 < row =< m_numRows and 0 < col =< m_numCols.
  //Post:  returns an unmodifiable reference to element T at the specified row and column.
  virtual const T& operator()(const int row, const int col) const;

/*  virtual int getCols() const { return upperTMatrix<T>::getCols(); };
  //Pre:  none.
  //Post:  returns an unmodifiable reference to m_numRows.
  virtual int getRows() const { return upperTMatrix<T>::getRows(); };
  //Pre:  none.
  //Post:  returns the value of m_flg.
  virtual int getFlg() const { return upperTMatrix<T>::getFlg(); };*/

  //Pre:   assignment must be defined for objects of type T.
  //Post:  if reference to matrixInt x does not reference *this matrixObj, overwrite this object
  //       to be a deep copy of x.  Returns a reference to this object.
  symmetricMatrix& operator=(const matrixInt<T>& x);
  //Pre:   assignment must be defined for objects of type T.
  //Post:  if reference to upperTMatrix x does not reference *this matrixObj, overwrite this object
  //       to be a deep copy of x.  Returns a reference to this object.
  symmetricMatrix& operator=(const symmetricMatrix<T>& x);
};

#include "symmetricMatrix.hpp"
#endif