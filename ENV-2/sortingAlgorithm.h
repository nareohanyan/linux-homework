#include <cmath>
#include <vector>

class ComplexNumbers {
public:
    ComplexNumbers() : r_part(0), im_part(0) {}
    ComplexNumbers(double real, double imaginary) : r_part(real), im_part(imaginary) {}

    double getSize();
    bool operator<(ComplexNumbers& other);

private:
    double r_part;
    double im_part;
};

void complexSort(std::vector<ComplexNumbers>& vec);
