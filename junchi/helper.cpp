#include "helper.h"
#include <iostream>

void vector_printer(const std::vector<int>& print_vector) {
    for (const auto& element : print_vector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
