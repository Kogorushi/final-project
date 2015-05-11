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

#define MAX_RANGE 3.1415926535897

using std::cout;

int main(int argc, char** argv)
{
  std::chrono::high_resolution_clock::time_point timeStart;
  std::chrono::high_resolution_clock::time_point timeEnd;
  std::chrono::duration<double> time_span;
  int n;
  fstream fileOutput1;
  fstream fileOutput2;
  uint32_t i;
  uint32_t j;

  if(argc < 2)
  {
    cout << "Invalid argument\n";
    cout << "Driver requires an integer for the mesh size." << endl;
    return 1;
  }

  n = atoi(argv[1]);

  fileOutput1.open("gnuDataCho.dat");
  fileOutput2.open("gnuDataGay.dat");

  fileOutput1 << "#X Y Z\n";
  fileOutput2 << "#X Y Z\n";


  cout << "~~~~~~~~~~~~~BEGINNING TESTING~~~~~~~~~~~~~\n";
  symmetricMatrix<float> A;
  vector<float> b, x;
  cout << "GENERATING MATRIX..." << endl;
  pdeMatrixGen<float, sin, zero, cos, zero>(A, b, n);

  cout << "~~~~~~~~~~~~~SOLVING FOR X~~~~~~~~~~~~~\n";
  cout << "...via Cholesky Decomposition..." << endl;
  lowerTMatrix<float> lT(A.getRows(), A.getCols());

  timeStart = std::chrono::high_resolution_clock::now();

  lT = cholesky(A);
  x = choleskySolver(lT, b);

  timeEnd = std::chrono::high_resolution_clock::now();
  time_span = ::chrono::duration_cast< ::chrono::duration<double> >(timeEnd - timeStart);

  cout << "x:\n" << x;

  for(i = 0; i < A.getCols(); ++i)
  {
    for(j = 0; j < A.getRows(); ++j)
    {
      fileOutput1 << (j+1)/MAX_RANGE << " " << (i+1)/MAX_RANGE << " " << A(j+1, i+1) << "\n";
    }
  }

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

  for(i = 0; i < A.getCols(); ++i)
  {
    for(j = 0; j < A.getRows(); ++j)
    {
      fileOutput2 << (j+1)/MAX_RANGE << " " << (i+1)/MAX_RANGE << " " << A(j+1, i+1) << "\n";
    }
  }

  cout << "Took time of: " << time_span.count() << " seconds." << endl;
  ofstream output;
  output.open("output.txt");
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
  return 0;
}
