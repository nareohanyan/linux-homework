#include "ComplexNumbers.h"

ComplexNumbers ComplexNumbers::operator+(const ComplexNumbers& c) {
  ComplexNumbers sum;
  sum.r_part = r_part + c.r_part;
  sum.im_part = im_part + c.im_part;
  return sum;
}

ComplexNumbers ComplexNumbers::operator-(const ComplexNumbers& c) {
  ComplexNumbers sub;
  sub.r_part = r_part - c.r_part;
  sub.im_part = im_part - c.im_part;
  return sub;
}

ComplexNumbers ComplexNumbers::operator*(std::size_t num) {
  ComplexNumbers mul;
  mul.r_part = r_part * num;
  mul.im_part = im_part * num;
  return mul;
}

double ComplexNumbers::complexAbs() {
  double abs;
  abs = std::sqrt(r_part * r_part + im_part * im_part);
  return abs;
}
