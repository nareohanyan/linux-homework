#include<iostream>
#include<cmath>

class ComplexNumbers {
private:
  double r_part;
  double im_part;

public:
  ComplexNumbers() : r_part(0), im_part(0) {}
  ComplexNumbers(double real, double imaginary) : r_part(real), im_part(imaginary) {}

  ComplexNumbers operator+(const ComplexNumbers& c);
  ComplexNumbers operator-(const ComplexNumbers& c);
  ComplexNumbers operator*(std::size_t num);
  
  double complexAbs();
};
