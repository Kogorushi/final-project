/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 4
/  DESC:  a header file for a matrixObj class that acts
/         like a mathematical matrix.
*/

#include <iostream>
using namespace std;

template <typename T>
matrix<T>::matrix()
{
  m_flg = 111;
  m_numRows = 0;
  m_numCols = 0;
}

template <typename T>
matrix<T>::matrix(int row, int col)
{
  m_flg = 111;
  m_numRows = 0;
  m_numCols = 0;
  buildNew(row, col);
}

template <typename T>
matrix<T>::matrix(const matrixInt<T>& x)
{
  m_flg = 111;
  m_numRows = 0;
  m_numCols = 0;
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    for(int i = 0; i < getRows()*getCols(); i++)
    {
      m_Matrix[i] = x((i/x.getCols()) + 1, (i%x.getCols()) + 1);
    }

  }
}

template <typename T>
matrix<T>::matrix(const matrix<T>& x)
{
  m_flg = 111;
  m_numRows = 0;
  m_numCols = 0;
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    for(int i = 0; i < getRows()*getCols(); i++)
    {
      m_Matrix[i] = x((i/x.getCols()) + 1, (i%x.getCols()) + 1);
    }
  }
}

template <typename T>
matrix<T>::~matrix()
{
  if(getRows() > 0 && getCols() > 0)
  {
    delete [] m_Matrix;
  }
}

template <typename T>
matrix<T>& matrix<T>::operator=(const matrixInt<T>& x)
{
  cout << "actually assigning something..." << endl;
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    for(int i = 0; i < getRows()*getCols(); i++)
    {
      m_Matrix[i] = x((i/x.getCols()) + 1, (i%x.getCols()) + 1);
    }

  }
  return *this;
}

template <typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& x)
{
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    for(int i = 0; i < getRows()*getCols(); i++)
    {
      m_Matrix[i] = x((i/x.getCols()) + 1, (i%x.getCols()) + 1);
    }

  }
  return *this;
}

template <typename T>
matrix<T>& matrix<T>::buildNew(const int row, const int col)
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
  if(row > 0 && col > 0 && getRows() == 0)
  {
    m_Matrix = new T[row*col];
    m_numRows = row;
    m_numCols = col;
  }
  for(int i = 0; i < getRows()*getCols(); i++)
  {
    m_Matrix[i] = 0;
  }
  return *this;
}

template <typename T>
T& matrix<T>::operator()(const int row, const int col)
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw 1;
  }
  return m_Matrix[((row - 1)*getCols() + col - 1)];
}

template <typename T>
const T& matrix<T>::operator()(const int row, const int col) const
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw 1;
  }
  return m_Matrix[(row - 1)*getCols() + col - 1];
}

template <typename T>
int matrix<T>::getRows() const
{
  return m_numRows;
}

template <typename T>
int matrix<T>::getCols() const
{
  return m_numCols;
}

template <typename T>
int matrix<T>::getFlg() const
{
  return m_flg;
}

template <typename T>
matrix<T> matrix<T>::transpose()
{
  matrix<T> retVal(getCols(), getRows());
  for(int i = 1; i <= getCols(); i++)
  {
    for(int j = 1; j <=getRows(); j++)
    {
      retVal(i, j) = (*this)(j, i);
    }
  }
  return retVal;
}