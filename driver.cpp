/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 5
/  DESC:  driver to test a Gaussian Elimination algorithm with Scaled Partial Pivoting
/         algorithm on a matrix class and a matrix Interface class for special matrices.
*/

#include <iostream>
#include <fstream>
#include "matrixLib.h"
#include "gaussElim.h"
#include "choleskyDecomp.h"
#include "gen_pde.h"
#include <cmath>
#include <ctime>
#include <chrono>
#define _USE_MATH_DEFINES

using std::cout;

int main(int argc, char** argv)
{
  std::chrono::high_resolution_clock::time_point timeStart;
  std::chrono::high_resolution_clock::time_point timeEnd;
  std::chrono::duration<double> time_span;
  int n;

  if(argc < 2)
  {
    cout << "Invalid argument\n";
    cout << "Driver requires an integer for the mesh size." << endl;
    return 1;
  }
  ofstream output;
  output.open("output.txt");
  n = atoi(argv[1]);

  cout << "~~~~~~~~~~~~~BEGINNING TESTING~~~~~~~~~~~~~\n";
  symmetricMatrix<float> A;
  vector<float> b, x;
  cout << "GENERATING MATRIX..." << endl;
  pdeMatrixGen<float, sin, zero, sin, zero>(A, b, n);
  cout << A << endl;
  cout << b << endl;
  cout << "~~~~~~~~~~~~~SOLVING FOR X~~~~~~~~~~~~~\n";
  cout << "...via Cholesky Decomposition..." << endl;
  lowerTMatrix<float> lT(A.getRows(), A.getCols());

  timeStart = std::chrono::high_resolution_clock::now();

  lT = cholesky(A);
  x = choleskySolver(lT, b);

  timeEnd = std::chrono::high_resolution_clock::now();
  time_span = ::chrono::duration_cast< ::chrono::duration<double> >(timeEnd - timeStart);

  cout << "x:\n" << x;
  output << time_span.count() << endl;
  cout << "Took time of: " << time_span.count() << " seconds." << endl;

  cout << "\n...via Gaussian Elimination..." << endl;
  gaussElim<float> t;
  matrix<float> mtrx(A);
  vector<float> tempB(b);

  timeStart = std::chrono::high_resolution_clock::now();

  x = t(mtrx, tempB);

  timeEnd = std::chrono::high_resolution_clock::now();
  time_span = ::chrono::duration_cast< ::chrono::duration<double> >(timeEnd - timeStart);

  cout << "x:\n" << x;
  cout << "Took time of: " << time_span.count() << " seconds." << endl;

  output << time_span.count() << endl;
  for(int i = 0; i < n*n; i++)
  {
    output << x[i];
    if((i+1)%n == 0)
    {
      output << "\n";
    }
    else
    {
      output << "\t";
    }
  }
  cout << "~~~~~~~~~~Populating True Value Vector~~~~~~~~~" << endl;
  vector<double> tVal(n*n);
  double xVal, yVal;
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      xVal = M_PI/(n+1)*j;
      yVal = M_PI/(n+1)*i;
      tVal[(i-1)*n+(j-1)] = (sin(xVal)*sinh(M_PI - yVal)+sin(yVal)*sinh(M_PI-xVal))/sinh(M_PI);
    }
  }
  cout << "~~~~~~~~~~Calculating Absolute Error~~~~~~~~~~~~" << endl;
  double err(0), maxT(0);  //calculating error using infinity norm
  for(int i = 1; i <= n*n; i++)
  {
    err = max(err, abs(tVal(i, 1) - x(i, 1)));
    maxT = max(maxT, abs(tVal(i, 1)));
  }
  cout << tVal<< endl;
  cout << maxT << "  " << err << "   " << endl;
  cout << "Absolute Error:  " << err/maxT << endl;
  output << "\n\n" << err/maxT << "\n";
  return 0;
}
