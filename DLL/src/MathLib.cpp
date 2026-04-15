#define MATHLIB_EXPORTS

#include "MathLib.h"
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

void printMessage() {
    std::cout << "Hello from DLL!" << std::endl;
    std::cout << "Goodbye keXin, I will miss u." << std::endl;
}