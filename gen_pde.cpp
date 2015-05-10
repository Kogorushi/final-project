#include <cstdint>

template <typename T, double (*X_0_FUNCTION)(double), double (*X_1_FUNCTION)(double), double (*Y_0_FUNCTION)(double), double (*Y_1_FUNCTION)(double)>
void pdeMatrixGen(symmetricMatrix<T> &A, vector<T> &B, const uint32_t n)
{
  uint32_t i;       /* loop iterator */
  uint64_t x;       /* relataive x coordinate */
  uint64_t y;       /* relative y coordinate */
  uint64_t xOffset; /* relative x offset coordinate*/
  uint64_t yOffset; /* relative y offset coordinate */

  A.buildNew(n*n, n*n);   /* generate new matrix of size (n*n+1) x (n*n+1) */
  B.buildNew(n*n);        /* generate new vector of size (n*n+1) */

  for(i = 0; i < A.getRows(); ++i) /* iterate over rows */
  {
    /* in a grid of:

    | (0,1)  ....  (1,1)
    |  :            :
    |  :            :
    | (0,0)  ....  (1,0)
    ____________________

    represent corrdinates as their column / row offset in an effortto reduce floating point division errors
    */

    /* find the correct x and y values */
    y = i/n;
    x = i%n;

    /* offset below the point */
    xOffset = x-1;
    yOffset = y;
    if(x == 0) /* check for boundry case along x axis */
    {
      B(i+1,1) = B(i+1,1) + X_0_FUNCTION(yOffset);
    }
    else
    {
      A( i+1, xOffset+yOffset*(n)+1 ) = -1.0/4;
    }

    /* offset above the point */
    xOffset = x+1;
    yOffset = y;
    if(xOffset == n) /* check for boundry case along x = 1 */
    {
      B(i+1,1) = B(i+1,1) + X_1_FUNCTION(yOffset);
    }
    else
    {
      A( i+1, xOffset+yOffset*(n)+1 ) = -1.0/4;
    }

    /* offset to the left of the point */
    xOffset = x;
    yOffset = y-1;
    if(y == 0) /* check for boundry case along y axis */
    {
      B(i+1,1) = B(i+1,1) + Y_0_FUNCTION(xOffset);
    }
    else
    {
      A( i+1, xOffset+yOffset*(n)+1 ) = -1.0/4;
    }

    /* offset to the right of the point */
    xOffset = x;
    yOffset = y+1;
    if(yOffset == n) /* check for boundry case along y = 1 */
    {
      B(i+1,1) = B(i+1,1) + Y_1_FUNCTION(xOffset);
    }
    else
    {
      A( i+1, xOffset+yOffset*(n)+1 ) = -1.0/4;
    }

    A(i+1,i+1) = 1;
  }

  return;
}
