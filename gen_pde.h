
#ifndef GEN_PDE_H
#define GEN_PDE_H

#include <cstdint>

#define MAX_RANGE 3.1415926535897

template <typename T, T (*X_0_FUNCTION)(T), T (*X_1_FUNCTION)(T), T (*Y_0_FUNCTION)(T), T (*Y_1_FUNCTION)(T)>
void pdeMatrixGen(symmetricMatrix<T> &A, vector<T> &B, const uint32_t n)
{
  int      i;       /* loop iterator */
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
      B(i+1,1) = B(i+1,1) + X_0_FUNCTION( static_cast<T>((yOffset+1))/n * MAX_RANGE );
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
      B(i+1,1) = B(i+1,1) + X_1_FUNCTION( static_cast<T>(yOffset+1)/n * MAX_RANGE );
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
      B(i+1,1) = B(i+1,1) + Y_0_FUNCTION( static_cast<T>(xOffset+1)/n * MAX_RANGE );
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
      B(i+1,1) = B(i+1,1) + Y_1_FUNCTION( static_cast<T>(xOffset+1)/n * MAX_RANGE);
    }
    else
    {
      A( i+1, xOffset+yOffset*(n)+1 ) = -1.0/4;
    }

    A(i+1,i+1) = 1;
    B(i+1,1) = B(i+1,1) / 4.0;
  }

  return;
}

template<typename T>
T zero(const T x)
{
  return x - x;
}

#endif
