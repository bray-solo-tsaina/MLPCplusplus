#include "reader.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


reader::reader() {
  this->filename = "null";
}

reader::reader(std::string filename) {
  this->filename = filename;
}

std::vector<std::vector<double>> reader::readFile() {
  std::vector<std::vector<double>> toRet;
  std::ifstream ifs(this->filename);
  std::string line;
  if(ifs.is_open()) {
    while(getline(ifs, line)) {
      std::string delimiter = ", ";

      size_t pos = 0;
      std::string token;
      std::vector<double> newR;
      
      while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        try {
          newR.push_back(std::stod(token));
        } catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << std::endl;
        }
        line.erase(0, pos + delimiter.length());
      }
      try {
        newR.push_back(std::stod(line));
      } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
      }
      toRet.push_back(newR);
    }
  } else {
    std::cout << "ERROR READING FILE" << std::endl;
    std::cout << this->filename << std::endl;
  }

  return toRet;
}
