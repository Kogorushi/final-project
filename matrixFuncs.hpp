


template <typename T>
matrix<T> operator+(const matrixInt<T>& lhs, const matrixInt<T>& rhs)
{
  if(lhs.getCols() != rhs.getCols() || lhs.getRows() != rhs.getRows())
  {
    throw length_error("matrices are of incompatible size");
  }
  matrix<T> retVal(lhs.getRows(), lhs.getCols());
  int c = lhs.getCols();
  int r = lhs.getRows();
  int cr = c*r;
  if(lhs.getFlg()%10 == 1 || rhs.getFlg()%10 == 1)
  {
    for(int i = 0; i < cr; i++)
    {
      if(i/c < i%c)
      {
        retVal(i/c + 1, i%c+1) = lhs(i/c + 1, i%c+1) + rhs(i/c + 1, i%c+1);
      }
      else
      {
        i = i + i/c;
      }
    }
  }
  if((lhs.getFlg()/10)%10 == 1 || (rhs.getFlg()/10)%10 == 1)
  {
    for(int i = 0; i < c; i++)
    {
      retVal(i+1, i+1) = lhs(i+1, i+1) + rhs(i+1, i+1);
    }
  }
  if((lhs.getFlg()/10)%10 == 2 || (rhs.getFlg()/10)%10 == 2)
  {
    for(int i = 1; i <= c; i++)
    {
      retVal(i, i) = lhs(i, i) + rhs(i, i);
      if(i+1 <= lhs.getCols())
      {
        retVal(i, i+1) = lhs(i, i+1) + rhs(i, i+1);
      }
      if(i+1 <= lhs.getRows())
      {
        retVal(i+1, i) = lhs(i+1, i) + rhs(i+1, i);
      }
    }
  }
  if((lhs.getFlg()/100)%10 == 1 || (rhs.getFlg()/100)%10 == 1)
  {
    for(int i = 0; i < cr; i++)
    {
      if(i/c > i%c)
      {
        retVal(i/c + 1, i%c+1) = lhs(i/c + 1, i%c+1) + rhs(i/c + 1, i%c+1);
      }
      else
      {
        i += (c-i/c) - 1;
      }
    }
  }
  return retVal;
}

template <typename T>
matrix<T> operator-(const matrixInt<T>& lhs, const matrixInt<T>& rhs)
{
  if(lhs.getCols() != rhs.getCols() || lhs.getRows() != rhs.getRows())
  {
    throw length_error("matrices are of incompatible size");
  }
  matrix<T> retVal(lhs.getRows(), lhs.getCols());
  int c = lhs.getCols();
  int r = lhs.getRows();
  int cr = c*r;
  if(lhs.getFlg()%10 == 1 || rhs.getFlg()%10 == 1)
  {
    for(int i = 1; i < cr; i++)
    {
      if(i/c < i%c)
      {
        retVal(i/c + 1, i%c+1) = lhs(i/c + 1, i%c+1) - rhs(i/c + 1, i%c+1);
      }
      else
      {
        i = i + i/c;
      }
    }
  }
  if((lhs.getFlg()/10)%10 == 1 || (rhs.getFlg()/10)%10 == 1)
  {
    for(int i = 0; i < c; i++)
    {
      retVal(i+1, i+1) = lhs(i+1, i+1) - rhs(i+1, i+1);
    }
  }
  if((lhs.getFlg()/10)%10 == 2 || (rhs.getFlg()/10)%10 == 2)
  {
    for(int i = 1; i <= c; i++)
    {
      retVal(i, i) = lhs(i, i) - rhs(i, i);
      if(i+1 <= lhs.getCols())
      {
        retVal(i, i+1) = lhs(i, i+1) - rhs(i, i+1);
      }
      if(i+1 <= lhs.getRows())
      {
        retVal(i+1, i) = lhs(i+1, i) - rhs(i+1, i);
      }
    }
  }
  if((lhs.getFlg()/100)%10 == 1 || (rhs.getFlg()/100)%10 == 1)
  {
    for(int i = 0; i < cr; i++)
    {
      if(i/c > i%c)
      {
        retVal(i/c + 1, i%c+1) = lhs(i/c + 1, i%c+1) - rhs(i/c + 1, i%c+1);
      }
      else
      {
        i += (c-i/c) - 1;
      }
    }
  }
  return retVal;
}
template <typename T>
matrix<T> operator*(const matrixInt<T>& lhs, const matrixInt<T>& rhs)
{
  if(lhs.getCols() != rhs.getRows())
  {
    throw length_error("matrices are of incompatible size");
  }
  matrix<T> retVal(lhs.getRows(), rhs.getCols());
  for(int i = 0; i < rhs.getCols(); i++)
  {
    for(int j = 0; j < lhs.getRows(); j++)
    {
      for(int k = 0; k < rhs.getRows(); k++)
      {
        if(k < j && (rhs.getFlg()%2 != 1 || (lhs.getFlg()/100)%10 != 1))
        {
          k = j - 1;
        }
        else if(k == j && ((rhs.getFlg()/10)%10 < 1 || (lhs.getFlg()/10)%10 < 1))
        {
          //Do Nothing.
        }
        else if(k == j && ((rhs.getFlg()/10)%10 == 2 || (lhs.getFlg()/10)%10 == 2))
        {
          retVal(j+1,i+1) += rhs(k+1, i+1)*lhs(j+1,k+1);
          if(k > 0)
          {
            retVal(j+1,i+1) += rhs(k, i+1)*lhs(j+1,k);
          }
          if(k+2 <= rhs.getRows())
          {
            retVal(j+1,i+1) += rhs(k+2, i+1)*lhs(j+1,k+2);
          }
        }
        else if(k > j && ((rhs.getFlg()/100)%10 != 1 || lhs.getFlg()%10 != 1))
        {
          k = rhs.getRows();
        }
        else
        {
          retVal(j+1,i+1) += rhs(k+1, i+1)*lhs(j+1,k+1);
        }
      }
    }
  }
  return retVal;
}

template <typename T>
matrix<T> operator*(const matrixInt<T>& lhs, const T rhs)
{
  int c = lhs.getCols();
  int r = lhs.getRows();
  int cr = c*r;
  matrix<T> retVal(r, c);
  if(lhs.getFlg()%10 == 1)
  {
    for(int i = 1; i < cr; i++)
    {
      if(i/c < i%c)
      {
        retVal(i/c + 1, i%c+1) = lhs(i/c + 1, i%c+1)*rhs;
      }
      else
      {
        i = i + i/c;
      }
    }
  }
  if((lhs.getFlg()/10)%10 == 1)
  {
    for(int i = 0; i < c; i++)
    {
      retVal(i+1, i+1) = lhs(i+1, i+1)*rhs;
    }
  }
  if((lhs.getFlg()/10)%10 == 2)
  {
    for(int i = 1; i <= c; i++)
    {
      retVal(i, i) = lhs(i, i)*rhs;
      if(i+1 <= lhs.getCols())
      {
        retVal(i, i+1) = lhs(i, i+1)*rhs;
      }
      if(i+1 <= lhs.getRows())
      {
        retVal(i+1, i) = lhs(i+1, i)*rhs;
      }
    }
  }
  if((lhs.getFlg()/100)%10 == 1)
  {
    for(int i = 0; i < cr; i++)
    {
      if(i/c > i%c)
      {
        retVal(i/c + 1, i%c+1) = lhs(i/c + 1, i%c+1)*rhs;
      }
      else
      {
        i += (c-i/c) - 1;
      }
    }
  }
  return retVal;
}

template <typename T>
ostream& operator<<(ostream& stream, const matrixInt<T>& c)
{
    for(int i = 1; i <= c.getRows(); i++)
  {
    stream << "| ";
    for(int j = 1; j <= c.getCols(); j++)
    {
      stream << c(i, j) << "\t";
    }
    stream << "|" << endl;
  }
  return stream;
}

template <typename T>
istream& operator>>(istream& lhs, matrixInt<T>& rhs)
{
  for( int i = 0; i < rhs.getRows()*rhs.getCols(); i++)
  {
    lhs >> rhs(i/rhs.getCols() + 1, i%rhs.getCols() + 1);
  }
  return lhs;
}
