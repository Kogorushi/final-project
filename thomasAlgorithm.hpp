




template <typename T>
vector<T> thomasAlgorithm(tridiagonalMatrix<T>& A, vector<T>& d)
{
  if(A.getRows() != A.getCols() || A.getRows() != d.getRows())
  {
    throw length_error("Invalid Matrix or vector size");
  }
  vector<T> retVal(d);
  T alpha = A(1, 1);
  A(1, 1) = A(1, 1) / alpha;
  d(1, 1) = d(1, 1) / alpha;
  if(A.getRows() > 1)
  {
    A(1, 2) = A(1, 2) / alpha;

    for(int i = 2; i <= A.getRows(); i++)
    {
      d(i, 1) = (d(i, 1) - A(i, i - 1)*d(i - 1, 1))/(A(i, i) - A(i, i - 1)*A(i-1, i));
      if(i != A.getRows())
      {
        A(i, i+1) = A(i, i+1) / (A(i, i) - A(i, i - 1)*A(i - 1, i));
      }
      A(i,i - 1) = 0;
    }
    retVal(A.getRows(), 1) = d(A.getRows(), 1);
    for(int i = A.getRows() - 1; i > 0; i--)
    {
      retVal(i, 1) = d(i, 1) - A(i, i + 1)*retVal(i+1, 1);
    }
  }
  return retVal;
}