 /*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 5
/  DESC:  an implementation file for a lowerTMatrix class that acts
/         like a mathematical matrix in upper echelon form.
*/

template<typename T>
lowerTMatrix<T>::lowerTMatrix()
{
  m_flg = 110;
  m_numRows = 0;
  m_numCols = 0;
}

template<typename T>
lowerTMatrix<T>::lowerTMatrix(int r, int c)
{
  m_flg = 110;
  m_numRows = 0;
  m_numCols = 0;
  buildNew(r, c);
}

template<typename T>
lowerTMatrix<T>::lowerTMatrix(matrixInt<T>& x)
{
  m_flg = 110;
  m_numRows = 0;
  m_numCols = 0;
  *this = x;
}

template<typename T>
lowerTMatrix<T>::lowerTMatrix(lowerTMatrix<T>& x)
{
  m_flg = 110;
  m_numRows = 0;
  m_numCols = 0;
  *this = x;
}

template<typename T>
lowerTMatrix<T>::~lowerTMatrix()
{
  if(getRows() > 0 && getCols() > 0)
  {
    delete [] m_Matrix;
  }
}

template<typename T>
T& lowerTMatrix<T>::operator()(const int row, const int col)
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw 1;
  }
  int r = row - 1;
  int c = col - 1;
  if(col<= row)
  {
    return m_Matrix[(r*r + r)/2 + c];
  }
  else
  {
    m_Matrix[(getCols()*getCols()+getCols())/2] = 0;
    return m_Matrix[(getCols()*getCols()+getCols())/2];
  }
}

template<typename T>
const T& lowerTMatrix<T>::operator()(const int row, const int col) const
{
  if(row < 1 || col < 1 || row > getRows() || col > getCols())
  {
    throw 1;
  }
  int r = row - 1;
  int c = col - 1;
  if(col<= row)
  {
    return m_Matrix[(r*r + r)/2 + c];
  }
  else
  {
    m_Matrix[(getCols()*getCols()+getCols())/2] = 0;
    return m_Matrix[(getCols()*getCols()+getCols())/2];
  }
}

template<typename T>
int lowerTMatrix<T>::getCols() const
{
  return m_numCols;
}

template<typename T>
int lowerTMatrix<T>::getRows() const
{
  return m_numRows;
}

template<typename T>
int lowerTMatrix<T>::getFlg() const
{
  return m_flg;
}

template<typename T>
lowerTMatrix<T>& lowerTMatrix<T>::operator=(const matrixInt<T>& x)
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
lowerTMatrix<T>& lowerTMatrix<T>::operator=(const lowerTMatrix<T>& x)
{
  if(this != &x)
  {
    buildNew(x.getRows(), x.getCols());
    int r, c;
    for(int i = 0; i < getRows()*getCols(); i++)
    {
      r = (i/x.getCols()) + 1;
      c = (i%x.getCols()) + 1;
      if(r < c)
      {
        i = r*x.getCols() - 1;
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
lowerTMatrix<T>& lowerTMatrix<T>::buildNew(const int row, const int col)
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