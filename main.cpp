#include "Kompilator.h"
#include <iostream>
#include <string>

int main() {
  std::string kod = "let i=2+2*2; print(i);";

  Kompilator komp;

  std::cout << komp.kompiluj(kod);

  return 0;
}
