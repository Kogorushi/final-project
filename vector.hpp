/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 4
/  DESC:  a header file for a matrixObj class that acts
/         like a mathematical matrix.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
vector<T>::vector()
{
  m_flg = 111;
  m_numRows = 0;
}

template <typename T>
vector<T>::vector(int row)
{
  m_flg = 111;
  m_numRows = 0;
  buildNew(row);
}

template <typename T>
vector<T>::vector(const matrixInt<T>& x)
{
  m_flg = 111;
  m_numRows = 0;
  if(this != &x)
  {
    buildNew(x.getRows());
    for(int i = 0; i < getRows(); i++)
    {
      m_Matrix[i] = x(i+1, 1);
    }

  }
}

template <typename T>
vector<T>::vector(const vector<T>& x)
{
  m_flg = 111;
  m_numRows = 0; 
  if(this != &x)
  {
    buildNew(x.getRows());
    for(int i = 0; i < getRows(); i++)
    {
      m_Matrix[i] = x(i+1, 1);
    }

  }
}

template <typename T>
vector<T>::~vector()
{
  if(getRows() > 0 && getCols() > 0)
  {
    delete [] m_Matrix;
  }
}

template <typename T>
vector<T>& vector<T>::operator=(const matrixInt<T>& x)
{
  if(this != &x)
  {
    buildNew(x.getRows());
    for(int i = 0; i < getRows(); i++)
    {
      m_Matrix[i] = x(i+1, 1);
    }

  }
  return *this;
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& x)
{
  if(this != &x)
  {
    buildNew(x.getRows());
    for(int i = 0; i < getRows(); i++)
    {
      m_Matrix[i] = x(i+1, 1);
    }

  }
  return *this;
}

template <typename T>
vector<T>& vector<T>::buildNew(const int row)
{
  if(getRows() != 0)
  {
    if(row < 1 || row != getRows())
    {
      m_numRows = 0;
      cout << "buildNew 1" << endl;
      delete [] m_Matrix;
    }
  }
  if(row > 0 && getRows() == 0)
  {
    m_Matrix = new T[row];
    m_numRows = row;
  }
  for(int i = 0; i < getRows(); i++)
  {
    m_Matrix[i] = 0;
  }
  return *this;
}

template <typename T>
T& vector<T>::operator()(const int row, const int col)
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw out_of_range( "Arguments out of bounds");
  }
  return m_Matrix[((row - 1)*getCols() + col - 1)];
}

template <typename T>
const T& vector<T>::operator()(const int row, const int col) const
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw out_of_range( "Arguments out of bounds");
  }
  return m_Matrix[(row - 1)*getCols() + col - 1];
}

template <typename T>
int vector<T>::getRows() const
{
  return m_numRows;
}

template <typename T>
int vector<T>::getCols() const
{
  return 1;
}

template <typename T>
int vector<T>::getFlg() const
{
  return m_flg;
}

template <typename T>
matrix<T> vector<T>::transpose()
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

template <typename T>
T& vector<T>::operator[](const int x)
{
  return (*this)(x+1, 1);
}

template<typename T>
const T& vector<T>::operator[](const int x) const
{
  return (*this)(x+1, 1);
}