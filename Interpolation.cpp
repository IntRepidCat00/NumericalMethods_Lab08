#include "Interpolation.h"

void Interpolation::enterData()
{
  std::cout << "Entering data:" << std::endl;
  std::cout << "Enter size: " << std::endl;
  std::cin >> size;
  std::cout << "Enter X Vector: " << std::endl;
  for(int i{0}; i < size; i++)
  {
    std::cout << "X[" << i << "]:" << std::endl;
    std::cin >> X[i];
  }
  std::cout << "Enter Y Vector: " << std::endl;
  for(int i{0}; i < size; i++)
  {
    std::cout << "Y[" << i << "]:" << std::endl;
    std::cin >> Y[i];
  }
  std::cout << "Enter x0:" << std::endl;
  std::cin >> x0;
  std::cout << "Data has been entered" << std::endl;
}

void Interpolation::printTable()
{
  std::string line(80, '-');

  std::cout << line << std::endl;
  std::cout << "| x | ";
  for(int i{0}; i < size; i++)
  {
    std::cout << X[i] << " | ";
  }
  std::cout << std::endl << "| y | ";
  for(int i{0}; i < size; i++)
  {
    std::cout << Y[i] << " | ";
  }
  std::cout << std::endl << line << std::endl;
}

void Interpolation::LagrangePoly()
{
  std::cout << "------------------ Lagrange Method ---------------------------------------------" << std::endl;
  std::cout << "x[0] = " << x0 << std::endl << std::endl;
  double solution{0};

  for(int i{0}; i < size; i++)
  {
    double Li{1};
    for(int j{0}; j < size; j++)
    {
      if(i != j)
      {
        Li *= (x0 - X[j])/(X[i]-X[j]);
      }
    }
    Li *= Y[i];
    std::cout << "Li[" << i << "] = " << Li << std::endl;
    solution += Li;
  }

  std::cout << std::endl << "| x[0] = "  << x0 << " | F(x[0]) = " << solution << " | " << std::endl;
}

double Interpolation::divDiff(int n0, int n)
{
  if(n - n0 < 1)
  {
    std::cout << "~Wrong data~" << std::endl;
    return -1;
  } else if(n - n0 == 1)
  {
    return ((Y[n]-Y[n0])/(X[n]-X[n0]));
  } else
  {
    return ((divDiff(n0+1, n) - divDiff(n0, n-1))/(X[n]-X[n0]));
  }
}

void Interpolation::NewtonPoly()
{
  std::cout << "------------------ Newton Method ---------------------------------------------" << std::endl;
  std::cout << "x[0] = " << x0 << std::endl << std::endl;
  double solution{0};
  for(int i{0}; i < size; i++)
  {
    double Li{Y[0]};
    if(i > 0)
    {
      Li = divDiff(0, i);
    }
    for(int j{0}; j < i; j++)
    {
      Li*=x0-X[j];
    }
    std::cout << "Li[" << i << "] = " << Li << std::endl;
    solution+=Li;
  }
  std::cout << std::endl << "| x[0] = "  << x0 << " | F(x[0]) = " << solution << " | " << std::endl;
}