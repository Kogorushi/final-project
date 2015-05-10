#include <cstdint>

//template <typename T, class X_0_FUNCTION (T), class Y_0_FUNCTION (T), class X_1_FUNCTION (T), class Y_1_FUNCTION (T)>
//template <void (*T)(int &)>
template <typename T, double (*X_0_FUNCTION)(double), double (*X_1_FUNCTION)(double), double (*Y_0_FUNCTION)(double), double (*Y_1_FUNCTION)(double)>
void pdeMatrixGen(symmetricMatrix<T> &A, vector<T> &B, const uint32_t n)
{
  uint32_t i; /* loop iterator */
  uint32_t j; /* loop iterator */

  uint64_t x;
  uint64_t y;
  uint64_t xOffset;
  uint64_t yOffset;

  A.buildNew(n*2+1, n*2+1); /* generate new matrix of size (n*n+1) x (n*n+1) */
  B.buildNew(n*2+1);        /* generate new vector of size (n*n+1) */

  for(i = 0; i < A.getRows(); ++i) /* iterate over rows */
  {
    cout << "testing: " << i << endl;
    /* in a grid of:

    | (0,1)  ....  (1,1)
    |  :            :
    |  :            :
    | (0,0)  ....  (1,0)
    ____________________

    represent corrdinates as their column / row offset in an effortto reduce floating point division errors
    */

    y = i/(n+1);
    x = i%(n+1);

    xOffset = x+1;
    yOffset = y;
    if(xOffset == n)
    {
      B(i,1) = B(i,1) + X_1_FUNCTION(yOffset);
    }
    else
    {
      cout << "throwing at:" << i << " " << xOffset+yOffset*(n-1) << endl;
      A( i, xOffset+yOffset*(n-1) ) = -1.0/4;
    }

    cout << "a" << endl;

    xOffset = x-1;
    yOffset = y;
    if(x == 0)
    {
      B(i,1) = B(i,1) + X_0_FUNCTION(yOffset);
    }
    else
    {
      A( i, xOffset+yOffset*(n-1) ) = -1.0/4;
    }

    cout << "b" << endl;

    xOffset = x;
    yOffset = y+1;
    if(yOffset == n)
    {
      B(i,1) = B(i,1) + Y_1_FUNCTION(xOffset);
    }
    else
    {
      A( i, xOffset+yOffset*(n-1) ) = -1.0/4;
    }

    cout << "c" << endl;

    xOffset = x;
    yOffset = y-1;
    if(y == 0)
    {
      B(i,1) = B(i,1) + Y_0_FUNCTION(xOffset);
    }
    else
    {
      A( i, xOffset+yOffset*(n-1) ) = -1.0/4;
    }

    cout << "d" << endl;

    A(i,i) = 1;

    cout << "e" << endl;
  }

  return;
}