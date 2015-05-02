 /*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 5
/  DESC:  an implementation file for a lowerTMatrix class that acts
/         like a mathematical matrix in upper echelon form.
*/

#include <stdexcept>

template<typename T>
symmetricMatrix<T>::symmetricMatrix()
{
  symmetricMatrix<T>::m_numRows = 0;
  symmetricMatrix<T>::m_numCols = 0;
  symmetricMatrix<T>::m_flg = 111;
}

template<typename T>
symmetricMatrix<T>::symmetricMatrix(int r, int c)
{
  symmetricMatrix<T>::m_numRows = 0;
  symmetricMatrix<T>::m_numCols = 0;
  symmetricMatrix<T>::m_flg = 111;
  symmetricMatrix<T>::buildNew(r, c);
}

template<typename T>
symmetricMatrix<T>::symmetricMatrix(matrixInt<T>& x)
{
  symmetricMatrix<T>::m_numRows = 0;
  symmetricMatrix<T>::m_numCols = 0;
  symmetricMatrix<T>::m_flg = 111;
  (*this) = x;
}

template<typename T>
symmetricMatrix<T>::symmetricMatrix(symmetricMatrix<T>& x)
{
  symmetricMatrix<T>::m_numRows = 0;
  symmetricMatrix<T>::m_numCols = 0;
  symmetricMatrix<T>::m_flg = 111;
  (*this) = x;
}

template<typename T>
symmetricMatrix<T>::~symmetricMatrix()
{
  /*if(symmetricMatrix<T>::getRows() > 0 && symmetricMatrix<T>::getCols() > 0)
  {
    delete [] symmetricMatrix<T>::m_Matrix;
  }*/
}

template<typename T>
T& symmetricMatrix<T>::operator()(const int row, const int col)
{
  if(row < 1 || col < 1 || row > symmetricMatrix<T>::getRows() || col > symmetricMatrix<T>::getCols())
  {
    throw out_of_range( "Arguments out of bounds");
  }
  int r = row - 1;
  int c = col - 1;
  if(col >= row)
  {
    return symmetricMatrix<T>::m_Matrix[r*symmetricMatrix<T>::getCols() + c - (r*r +r)/2];
  }
  else
  {
    return symmetricMatrix<T>::m_Matrix[c*symmetricMatrix<T>::getCols() + r - (c*c + c)/2];
  }
}

template<typename T>
const T& symmetricMatrix<T>::operator()(const int row, const int col) const
{
  if(row < 1 || col < 1 || row > symmetricMatrix<T>::getRows() || col > symmetricMatrix<T>::getCols())
  {
    throw out_of_range( "Arguments out of bounds");
  }
  int r = row - 1;
  int c = col - 1;
  if(col >= row)
  {
    return symmetricMatrix<T>::m_Matrix[r*symmetricMatrix<T>::getCols() + c - (r*r +r)/2];
  }
  else
  {
    return symmetricMatrix<T>::m_Matrix[c*symmetricMatrix<T>::getCols() + r - (c*c + c)/2];
  }
}

template<typename T>
symmetricMatrix<T>& symmetricMatrix<T>::operator=(const matrixInt<T>& x)
{
  if(this != &x)
  {
    symmetricMatrix<T>::buildNew(x.getRows(), x.getCols());
    int r, c;
    for(int i = 0; i < symmetricMatrix<T>::getRows()*symmetricMatrix<T>::getCols(); i++)
    {
      r = (i/x.getCols()) + 1;
      c = (i%x.getCols()) + 1;
      if(r > c)
      {
        i = i + r - 2;
      }
      else
      {
        (*this)(r, c)  = x(r, c);
      }
    }
  }
  return *this;
}

template<typename T>
symmetricMatrix<T>& symmetricMatrix<T>::operator=(const symmetricMatrix<T>& x)
{
  if(this != &x)
  {
    symmetricMatrix<T>::buildNew(x.getRows(), x.getCols());
    int r, c;
    for(int i = 0; i < symmetricMatrix<T>::getRows()*symmetricMatrix<T>::getCols(); i++)
    {
      r = (i/x.getCols()) + 1;
      c = (i%x.getCols()) + 1;
      if(r > c)
      {
        i = i + r - 2;
      }
      else
      {
        (*this)(r, c)  = x(r, c);
      }
    }
  }
  return *this;
}
