/*
/  Luke H Holliday
/  CS 5201 Section 1a
/  assignment 5
/  DESC:  a header file for an interface class matrixInt.
*/


#ifndef MATRIX_INTERFACE_H
#define MATRIX_INTERFACE_H

template <typename T>
class matrixInt
{
  public:
    virtual T& operator()(const int, const int) = 0;
    virtual const T& operator()(const int, const int) const = 0;
    virtual int getCols() const = 0;
    virtual int getRows() const = 0;
    virtual int getFlg() const = 0;
    //virtual ~martixInt();
};

#endif