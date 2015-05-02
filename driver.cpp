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
#include "thomasAlgorithm.h"
#include "choleskyDecomp.h"

using namespace std;

int main(int argc, char** argv)
{
  if(argc < 2)
  {
    cout << "Invalid argument" << endl;
    cout << "Driver requires a properly formatted input file.  Please rerun" << endl;
    cout << "program with input file." << endl;
    cout << "driver <file Name>.txt" << endl;
    return 1;
  }

  ifstream file;
  file.open(argv[1]);

  int size;
  file >> size;

  cout << "~~~~~~~~~~~BEGINNING TESTING~~~~~~~~~~" << endl;
  tridiagonalMatrix<float> temp;
  tridiagonalMatrix<float> mtrx(size, size);
//  upperTMatrix<float> mtrx(size, size);  //you can test these by commenting out the matrix class and the gaussian
//  lowerTMatrix<float> mtrx(size, size);  //elimination at the bottom of the driver.
  
  file >> mtrx;
  cout << mtrx;
  cout << "~~~~~~~~~~TESTING ACCESSORS~~~~~~~~~~~" << endl;
  cout << "Size of matrix temp is " << temp.getRows() << "x" << temp.getCols() << ". (DEFAULT 0x0)" << endl;
  cout << "Size of matrix mtrx is " << mtrx.getRows() << "x" << mtrx.getCols() << endl;
  cout << "Element A11 of mtrx is " << mtrx(1, 1) << endl;
  cout << "Element A42 of mtrx is " << mtrx(4, 2) << endl;
  cout << "Writing 1.5 to A11..." << endl;
  mtrx(1, 1) = 1.5;
  cout << "Element A11 of mtrx is " << mtrx(1, 1) << ". (actual 1.5)" << endl;
  mtrx(1, 1) = 11;
  cout << "Writing matrix to stream:" << endl;
  cout << mtrx;
  vector<float> b(size);
  file >> b;
  
  vector<float> originalb(b);

  vector<float> x(b);
  cout << b(1, 1) << endl;
  x(1, 1) = 0;
  cout << b(1, 1) << endl; 
  matrix<float> temp2(mtrx);
  matrix<float> temp3(mtrx);
  matrix<float> a(1, 4);
  cout << "YO!" << endl;
  cout << mtrx << endl;
  cout << temp2 << endl;
  for(int i = 1; i < 5; i++)
  {  
    a(1,i) = 1;
  }
  cout << "didn't break yet..." << endl;
  temp3 = (mtrx * temp2);
  b = mtrx * x;
  cout << "MATRIX-VECTOR MULTIPLICATION" << endl;
  cout << mtrx << endl << x << endl << "RESULT:  " << b << endl;
  cout << "MATRIX MULTIPLICATION (x*x)" << endl;
  cout << "x:" << endl << mtrx << endl << "RESULT:" << endl << temp3 << endl;
  cout << "a*aT ( a = | 1 1 1 1 | ) = " << a*a.transpose() << endl;
  cout << "aT*a" << endl;
  cout << a.transpose() * a << endl;
  cout << "SCALAR MULTIPLICATION" << endl;
  temp3 = mtrx * static_cast<float>(2);
  cout << "Matrix:" << endl << mtrx << "multiple: 2" << endl << temp3 << endl;
  temp3 = mtrx - mtrx;
  cout << "SUBTRACTION OF MATRIXES (x - x)" << endl << temp3;
  cout << "ADDITION OF MATRICES (x + x)" << endl;
  temp3 = mtrx + mtrx;
  cout << temp3;
  cout << "TESTING x = x" << endl;
  cout << "Before:" << endl << mtrx;
  mtrx = mtrx;
  cout << "After:" << endl << mtrx << endl;

  temp3 = mtrx;
  b = originalb;
  cout << "STARTING THOMAS ALGORITHM" << endl;
  x = thomasAlgorithm(mtrx, b);
  cout << "Calculated value of x:" << endl;
  cout << x << endl;
  cout << "Ax = " << (temp3*x) << ".  (original is: " << originalb << ")" << endl;
  file >> size;
  cout << "~~~~~~~~CHOLESKY DECOMP~~~~~~~~~" << endl;
  symmetricMatrix<float> sym(size, size);
  file >> sym;
  vector<float> newB(size);
  file >> newB;
  cout << "made it here" << endl;
  lowerTMatrix<float> lT(size, size);
  lT = cholesky(sym);
  cout << lT << endl;
  cout << newB << endl;
  x = choleskySolver(lT, newB);
  cout << "Ax = " << (sym*x) << ".  (original is: " << newB << ")" << endl;
/*  gaussElim<float> t;
  temp3 = mtrx;
  b = originalb;
  cout << "~~~~~~~~GAUSSIAN ELIMINATION~~~~~~~~~" << endl;
  x = t(mtrx, b);
  cout << "A in row echelon form:" << endl;
  cout << mtrx << endl;
  cout << "Calculated value of x:" << endl;
  cout << x << endl;
  cout << "Ax = " << (temp3*x) << ".  (original is: " << originalb << ")" << endl;*/
  return 0;
}