/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 5
/  DESC:  an implementation file for a lowerTMatrix class that acts
/         like a mathematical matrix in upper echelon form.
*/

#include <stdexcept>
#include <cmath>

template<typename T>
tridiagonalMatrix<T>::tridiagonalMatrix()
{
  m_flg = 20;
  m_numRows = 0;
  m_numCols = 0;
  s = 0;
}

template<typename T>
tridiagonalMatrix<T>::tridiagonalMatrix(int r, int c)
{
  m_flg = 20;
  m_numRows = 0;
  m_numCols = 0;
  s = 0;
  buildNew(r, c);
}

template<typename T>
tridiagonalMatrix<T>::tridiagonalMatrix(matrixInt<T>& x)
{
  m_flg = 20;
  m_numRows = 0;
  m_numCols = 0;
  s = 0;
  *this = x;
}

template<typename T>
tridiagonalMatrix<T>::tridiagonalMatrix(tridiagonalMatrix<T>& x)
{
  m_flg = 20;
  m_numRows = 0;
  m_numCols = 0;
  s = 0;
  *this = x;
}

template<typename T>
tridiagonalMatrix<T>::~tridiagonalMatrix()
{
  if(getRows() > 0 && getCols() > 0)
  {
    delete [] m_Matrix;
  }
}

template<typename T>
T& tridiagonalMatrix<T>::operator()(const int row, const int col)
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw out_of_range( "Arguments out of bounds");
  }
  int r = row - 1;
  int c = col - 1;
  if(abs(row - col) < 2)
  {
    if(getRows() > getCols() && row == getRows())
    {
      return m_Matrix[(r-1)*3 + 1];
    }
    else
    {
      return m_Matrix[r*3 + (c - r)];
    }
  }
  else
  {
    m_Matrix[s] = 0;
    return m_Matrix[s];
  }
}

template<typename T>
const T& tridiagonalMatrix<T>::operator()(const int row, const int col) const
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw out_of_range( "Arguments out of bounds");
  }
  int r = row - 1;
  int c = col - 1;
  if(abs(row - col) < 2)
  {
    if(getRows() > getCols() && row == getRows())
    {
      return m_Matrix[(r-1)*3 + 1];
    }
    else
    {
      return m_Matrix[r*3 + (c - r)];
    }
  }
  else
  {
    m_Matrix[s] = 0;
    return m_Matrix[s];
  }
}

template<typename T>
int tridiagonalMatrix<T>::getCols() const
{
  return m_numCols;
}

template<typename T>
int tridiagonalMatrix<T>::getRows() const
{
  return m_numRows;
}

template<typename T>
int tridiagonalMatrix<T>::getFlg() const
{
  return m_flg;
}

template<typename T>
tridiagonalMatrix<T>& tridiagonalMatrix<T>::operator=(const matrixInt<T>& x)
{
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    for(int i = 1; i <= min(getCols(), getRows()); i++)
    {
      (*this)(i, i) = x(i, i);
      if(i+1 <= getCols())
      {
        (*this)(i, i+1) = x(i, i+1);
      }
      if(i+1 <= getRows())
      {
        (*this)(i+1, i) = x(i+1, i);
      }
    }
  }
  return *this;
}

template<typename T>
tridiagonalMatrix<T>& tridiagonalMatrix<T>::operator=(const tridiagonalMatrix<T>& x)
{
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    for(int i = 1; i <= min(getCols(), getRows()); i++)
    {
      (*this)(i, i) = x(i, i);
      if(i+1 <= getCols())
      {
        (*this)(i, i+1) = x(i, i+1);
      }
      if(i+1 <= getRows())
      {
        (*this)(i+1, i) = x(i+1, i);
      }
    }
  }
  return *this;
}

template<typename T>
tridiagonalMatrix<T>& tridiagonalMatrix<T>::buildNew(const int row, const int col)
{
  if(getRows() != 0)
  {
    if(row < 1 || col < 1 || row*col != getRows()*getCols())
    {
      m_numRows = 0;
      m_numCols = 0;
      delete [] m_Matrix;
    }
  }
  s = min(col, row) + 2*(col - 1);
  if(row != col)
  {
    s+= 1;
  }
  if(row > 0 && col > 0 && getRows() == 0)
  {
    m_Matrix = new T[s+1];
    m_numRows = row;
    m_numCols = col;
  }
  for(int i = 0; i <= s; i++)
  {
    m_Matrix[i] = 0;
  }
  return *this;
}