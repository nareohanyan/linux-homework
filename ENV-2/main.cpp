#include<iostream>
#include"sortingAlgorithm.h"

int main() {
  std::vector<ComplexNumbers> vec;
  vec.push_back(ComplexNumbers(4.0, 8.0));
  vec.push_back(ComplexNumbers(5.2, 9.1));
  vec.push_back(ComplexNumbers(12.8, 41.5));
  vec.push_back(ComplexNumbers(8.2, 7.0));
  vec.push_back(ComplexNumbers(2.3, 4.5));
  vec.push_back(ComplexNumbers(11.3, 5.0));

  complexSort(vec);
  for(ComplexNumbers& c : vec) {
    std::cout << c.getSize() << " " << std::endl;
  }
}