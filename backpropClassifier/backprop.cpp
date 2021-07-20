#include <vector>
#include <string>
#include <iostream>

#include "../datareading/reader.h"
#include "../datareading/reader.cpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "INCORRECT USAGE, ./backprop + \"pathtofile\"";
    return 0;
  }
  reader rd(argv[1]);
  std::vector<std::vector<double>> data = rd.readFile();
  for(int i = 0; i < data.size(); i++) {
    for(int j = 0; j < data[i].size(); j++) {
      std::cout << data[i][j] << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
