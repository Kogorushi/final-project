

template <typename T>
lowerTMatrix<T> cholesky(symmetricMatrix<T>& A)
{
  lowerTMatrix<T> retVal(A.getRows(), A.getCols());
  T s = 0;
  for(int i = 1; i <= A.getRows(); i++)
  {
    for(int j = 1; j < i+1; j++)
    {
      s = 0;
      for(int k = 1; k < j; k++)
      {
        s += retVal(i, k)*retVal(j, k);
      }
      if( i == j)
      {
        retVal(i, j) = sqrt(A(i, i) - s);
      }
      else
      {
        retVal(i, j) = (A(i, j) - s)/retVal(j, j);
      }
    }
/*    retVal(i, i) = sqrt(A(i, i) - s);

    for(int k = i + 1; k <= A.getRows(); k++)
    {
      s = 0;
      for(int j = 1; j < i; j++)
      {
        s += retVal(i, j)*retVal(k, j);
      }
      retVal(k, i) = (A(k, i) - s)/retVal(i, i);
    }*/
  }
  return retVal;
}

template <typename T>
vector<T> choleskySolver(const lowerTMatrix<T>& A, const vector<T>& b)
{
  vector<T> retVal(b.getRows()), temp(b.getRows());
  T scalar = 0;
  for(int i = A.getCols(); i > 0; i--)
  {
    scalar = 0;
    for(int j = i; j < A.getCols(); j++)
    {
      scalar = scalar + temp[j] * A(i,j+1);
    }
    if(A(i, i) != 0)
    {
      temp[i - 1] = (b[i - 1] - scalar)/A(i,i);
    }
  }
  for(int i = A.getCols(); i > 0; i--)
  {
    scalar = 0;
    for(int j = i; j < A.getCols(); j++)
    {
      scalar = scalar + retVal[j] * A(j+1,i);
    }
    if(A(i, i) != 0)
    {
      retVal[i - 1] = (temp[i - 1] - scalar)/A(i,i);
    }
  } 
  return retVal;
}
