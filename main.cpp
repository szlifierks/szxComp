#include "Kompilator.h"
#include <iostream>
#include <string>

int main() {
    std::string kod = "let i=0; print(i);";

    Kompilator komp;

    std::cout << komp.kompiluj(kod,"-t");

    return 0;
}