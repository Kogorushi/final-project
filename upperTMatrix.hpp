 /*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 5
/  DESC:  an implementation file for a upperTMatrix class that acts
/         like a mathematical matrix in upper echelon form.
*/


 //Constructor/Destructors
  //Pre:  none.
  //Post:  initializes m_numRows and m_numCols to 0 and m_flg to 011.
template<typename T>
upperTMatrix<T>::upperTMatrix()
{
  m_flg = 011;
  m_numRows = 0;
  m_numCols = 0;
}
  //Pre: none;  r and c should be greater than 0, but it isn't necessary.
  //Post:  If row > 0 and col > 0, initializes m_Matrix to be a new array of size row*col
  //       and sets each value in m_Matrix to 0.
  //       Otherwise, sets m_numRows and m_numCols to 0.  Also, sets m_flg to 011.
template<typename T>
upperTMatrix<T>::upperTMatrix(int r, int c)
{
  m_flg = 11;
  m_numRows = 0;
  m_numCols = 0;
  buildNew(r, c);
}
  //Pre:  none.
  //Post:  If reference to matrixInt x does not reference *this, overwrites the current
  //       object, *this, to be a deep copy of the upper right part of x. (can be used to copy
  //       a full matrix into an upperTMatrix)
template<typename T>
upperTMatrix<T>::upperTMatrix(matrixInt<T>& x)
{
  m_flg = 11;
  m_numRows = 0;
  m_numCols = 0;
  *this = x;
}
  

template<typename T>
upperTMatrix<T>::upperTMatrix(upperTMatrix<T>& x)
{
  m_flg = 11;
  m_numRows = 0;
  m_numCols = 0;
  *this = x;
}

template<typename T>
upperTMatrix<T>::~upperTMatrix()
{
  if(getRows() > 0 && getCols() > 0)
  {
    delete [] m_Matrix;
  }
}

template<typename T>
T& upperTMatrix<T>::operator()(const int row, const int col)
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw 1;
  }
  int r = row - 1;
  int c = col - 1;
  if(col>= row)
  {
    return m_Matrix[r*getCols() + c - (r*r +r)/2];
  }
  else
  {
    m_Matrix[(getCols()*getCols()+getCols())/2] = 0;
    return m_Matrix[(getCols()*getCols()+getCols())/2];
  }
}

template<typename T>
const T& upperTMatrix<T>::operator()(const int row, const int col) const
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw 1;
  }
  int r = row - 1;
  int c = col - 1;
  if(col>= row)
  {
    return m_Matrix[r*getCols() + c - (r*r +r)/2];
  }
  else
  {
    m_Matrix[(getCols()*getCols()+getCols())/2] = 0;
    return m_Matrix[(getCols()*getCols()+getCols())/2];
  }
}

template<typename T>
int upperTMatrix<T>::getCols() const
{
  return m_numCols;
}

template<typename T>
int upperTMatrix<T>::getRows() const
{
  return m_numRows;
}

template<typename T>
int upperTMatrix<T>::getFlg() const
{
  return m_flg;
}

template<typename T>
upperTMatrix<T>& upperTMatrix<T>::operator=(const matrixInt<T>& x)
{
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    int r, c;
    for(int i = 0; i < getRows()*getCols(); i++)
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
upperTMatrix<T>& upperTMatrix<T>::operator=(const upperTMatrix<T>& x)
{
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    int r, c;
    for(int i = 0; i < getRows()*getCols(); i++)
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
upperTMatrix<T>& upperTMatrix<T>::buildNew(const int row, const int col)
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
  int s = (col*col + col)/2;
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