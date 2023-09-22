#include <cmath>
#include <vector>

class ComplexNumbers {
private:
    double r_part;
    double im_part;

public:
    ComplexNumbers() : r_part(0), im_part(0) {}
    ComplexNumbers(double real, double imaginary) : r_part(real), im_part(imaginary) {}

    double getSize();
    bool operator<(ComplexNumbers& other);
};

void sort(std::vector<ComplexNumbers>& vec);
