/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 6
/  DESC:  an implementation file for a diagonalMatrix class that acts
/         like a mathematical matrix.
*/

#include <stdexcept>
#include <cmath>

template<typename T>
diagonalMatrix<T>::diagonalMatrix()
{
  m_flg = 10;
  m_numRows = 0;
  m_numCols = 0;
}

template<typename T>
diagonalMatrix<T>::diagonalMatrix(int r, int c)
{
  m_flg = 10;
  m_numRows = 0;
  m_numCols = 0;
  buildNew(r, c);
}

template<typename T>
diagonalMatrix<T>::diagonalMatrix(matrixInt<T>& x)
{
  m_flg = 10;
  m_numRows = 0;
  m_numCols = 0;
  *this = x;
}

template<typename T>
diagonalMatrix<T>::diagonalMatrix(diagonalMatrix<T>& x)
{
  m_flg = 10;
  m_numRows = 0;
  m_numCols = 0;
  *this = x;
}

template<typename T>
diagonalMatrix<T>::~diagonalMatrix()
{
  if(getRows() > 0 && getCols() > 0)
  {
    delete [] m_Matrix;
  }
}

template<typename T>
T& diagonalMatrix<T>::operator()(const int row, const int col)
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw out_of_range( "Arguments out of bounds");
  }
  int c = col - 1;
  if(col == row)
  {
    return m_Matrix[c];
  }
  else
  {
    m_Matrix[getCols()] = 0;
    return m_Matrix[min(getCols(), getRows())];
  }
}

template<typename T>
const T& diagonalMatrix<T>::operator()(const int row, const int col) const
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw out_of_range( "Arguments out of bounds");
  }
  int c = col - 1;
  if(col == row)
  {
    return m_Matrix[c];
  }
  else
  {
    m_Matrix[getCols()] = 0;
    return m_Matrix[min(getCols(), getRows())];
  }
}

template<typename T>
int diagonalMatrix<T>::getCols() const
{
  return m_numCols;
}

template<typename T>
int diagonalMatrix<T>::getRows() const
{
  return m_numRows;
}

template<typename T>
int diagonalMatrix<T>::getFlg() const
{
  return m_flg;
}

template<typename T>
diagonalMatrix<T>& diagonalMatrix<T>::operator=(const matrixInt<T>& x)
{
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    for(int i = 1; i <= min(getCols(), getRows()); i++)
    {
      (*this)(i, i) = x(i, i);
    }
  }
  return *this;
}

template<typename T>
diagonalMatrix<T>& diagonalMatrix<T>::operator=(const diagonalMatrix<T>& x)
{
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    for(int i = 1; i <= min(getCols(), getRows()); i++)
    {
      (*this)(i, i) = x(i, i);
    }
  }
  return *this;
}

template<typename T>
diagonalMatrix<T>& diagonalMatrix<T>::buildNew(const int row, const int col)
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
  int s = min(col, row);
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