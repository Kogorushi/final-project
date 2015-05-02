/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 5
/  DESC:  an implementation file for a gaussElim functor class that 
/         uses a Gaussian Elimination Algorithm with Scaled Partial Pivoting.
*/

template <typename T>
void gaussElim<T>::rowAdd(int target, int rowNum, T scalar, matrix<T>& A, vector<T>& b)
{
  for(int i = 1; i <= A.getCols(); i++)
  {
    A(target, i) = A(target, i) + A(rowNum, i) * scalar;
  }
  b[target - 1] = b[target - 1] + b[rowNum - 1] * scalar;
}

template <typename T>
void gaussElim<T>::rowSwap(int target1, int target2, matrix<T>& A, vector<T>& b)
{
  T temp;
  for(int i = 1; i <= A.getCols(); i++)
  {
    temp = A(target1,i);
    A(target1, i) = A(target2, i);
    A(target2, i) = temp;

  }
  temp = b[target1 - 1];
  b[target1 - 1] = b[target2 - 1];
  b[target2 - 1] = temp;
}

template <typename T>
vector<T> gaussElim<T>::operator()(matrix<T>& A, vector<T>& b)
{
  vector<T> x(b);
  int p = 1;
  T scalar;
  T* s = new T[A.getRows()];
  for(int i = 0; i < A.getRows(); i++)
  {
    s[i] = 0;
    for(int j = 0; j < A.getCols(); j++)
    {
      if(s[i] < abs(A(i+1,j+1)))
      {
        s[i] = abs(A(i+1, j+1));
      }
    }
  }
  for(int i = 1; i <= A.getCols(); i++)
  {
    p = i;
    for(int k = i + 1; k <= A.getCols(); k++)
    {
      if(abs(A(p, i))/s[p-1] < abs(A(k, i))/s[k-1])
      {
        p = k;
      }
    }
    if(p != i)
    {
      rowSwap(i, p, A, b);
    }
    for(int k = i + 1; k <= A.getCols(); k++)
    {
      scalar = -A(k,i)/A(i,i);
      rowAdd(k, i, scalar, A, b);
      A(k,i) = 0;
    }
  }
  for(int i = A.getCols(); i > 0; i--)
  {
    scalar = 0;
    for(int j = i; j < A.getCols(); j++)
    {
      scalar = scalar + x[j] * A(i,j+1);
    }
    if(A(i, i) != 0)
    {
      x[i - 1] = (b[i - 1] - scalar)/A(i,i);
    }
  }
  delete [] s;
  return x;
}