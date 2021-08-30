#include <vector>
#include <string>
#include <iostream>

#include "../datareading/reader.cpp"
#include "../array2d/array2d.h"
#include "MLPClassifier.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "INCORRECT USAGE, ./backprop + \"pathtofile\"";
    return 0;
  }
  reader rd(argv[1]);
  std::vector<std::vector<double>> data = rd.readFile();
  MLPClassifier mlp;
  mlp.fit(data);

  return 0;
}
