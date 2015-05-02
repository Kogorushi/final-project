/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 5
/  DESC:  a header file for a vector class that acts
/         like a mathematical vector and is compatible with a matrix Interface.
*/

#ifndef VECTOR_H
#define VECTOR_H
#include "matrixInterface.h"
#include "matrix.h"

template <typename T>
class vector : public matrixInt<T>
{
  private:
  T* m_Matrix;
  int m_numRows;
  int m_flg;
  public:
  //Constructor/Destructors
  //Pre:  none.
  //Post:  initializes m_numRows to 0 and m_flg to 111.
  vector();
  //Pre: none;  rows should be greater than 0, but it isn't necessary.
  //Post:  If rows > 0 , initializes m_Matrix to be a new array of size rows
  //       and sets each value in m_Matrix to 0.
  //       Otherwise, sets m_numRows to 0.  Sets m_flg to 111.
  vector(int rows);
  //Pre:  none.
  //Post:  If reference to matrixInt x does not reference *this, overwrites the current
  //       object, *this, to be a deep copy of x.
  vector(const matrixInt<T>& x);
  //Pre:  none.
  //Post:  If reference to matrixInt x does not reference *this, overwrites the current
  //       object, *this, to be a deep copy of x.
  vector(const vector<T>& x);
  //Pre:  none.
  //Post:  if m_numRows > 0, deletes m_Matrix and sets m_numRows = 0.
  ~vector();

  //ASSIGNMENTS
  //Pre:   assignment must be defined for objects of type T.
  //Post:  if reference to matrixInt x does not reference *this matrixObj, overwrite this object
  //       to be a deep copy of x.  Returns a reference to this object.
  vector& operator=(const matrixInt<T>& x);
  //Pre:   assignment must be defined for objects of type T.
  //Post:  if reference to matrixInt x does not reference *this matrixObj, overwrite this object
  //       to be a deep copy of x.  Returns a reference to this object.
  vector& operator=(const vector<T>& x);
  //Pre:   assignment and default construction must be defined for objects of type T.
  //       Objects of type T must be assignable to 0.
  //Post:  If row > 0 and col > 0 and row differs from m_numRows,
  //       deletes m_Matrix and creates a new m_Matrix of size row and set m_numRows = row.
  //       If row is less than 1 and m_numRows > 0, delete m_Matrix.  
  //       Then, if row > 0, initializes the values of m_Matrix to 0.
  //       Otherwise, sets m_numRows = 0.  Returns a reference to this object.
  vector& buildNew(const int row);

  //ACCESSORS
  //Pre:  0 < row =< m_numRows and col == 1.
  //Post:  returns a modifiable reference to element T at the specified row and column.
  virtual T& operator()(const int row, const int col);
  //Pre:  0 < row =< m_numRows and col == 1.
  //Post:  returns an unmodifiable reference to element T at the specified row and column.
  virtual const T& operator()(const int row, const int col) const;
  //Pre:  none.
  //Post:  returns an unmodifiable reference to m_numRows.
  virtual int getRows() const;
  //Pre:  none.
  //Post:  returns an unmodifiable reference to m_numCols.
  virtual int getCols() const;
  //Pre:  none.
  //Post:  returns an unmodifiable reference to m_flg.
  virtual int getFlg() const;

  //Pre:  0 <= row < m_numRows.
  //Post:  returns a modifiable reference to element T at the specified row.
  T& operator[](const int);
  //Pre:  0 <= row < m_numRows.
  //Post:  returns an unmodifiable reference to element T at the specified row.
  const T& operator[](const int) const;


  //Pre:  assignment must be defined for objects of type T.
  //Post:  returns a matrix that is equal to this matrix transposed.
  matrix<T> transpose();
};

#include "vector.hpp"
#endif