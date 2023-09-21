#include"sortingAlgorithm.h"

double ComplexNumbers::getSize() {
    return std::sqrt(r_part * r_part + im_part * im_part);
}

bool ComplexNumbers::operator<(ComplexNumbers& other) {
    return getSize() < other.getSize();
}

void complexSort(std::vector<ComplexNumbers>& vec) {
    int n = vec.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] < vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
