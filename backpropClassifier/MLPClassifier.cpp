#include "MLPClassifier.h"

MLPClassifier::MLPClassifier() {
  this->learningRate = 0.1;
  this->momentum = 0;
}

void MLPClassifier::fit(std::vector<std::vector<double>> inputs) {
  std::vector<std::vector<double>> X;
  std::vector<std::vector<double>> y;
  for (int i = 0; i < inputs.size(); i++) {
    std::vector<double> newRX;
    std::vector<double> newRy;
    for (int j = 0; j < inputs[i].size(); j++) {
      if (j != inputs[i].size() - 1) {
        newRX.push_back(inputs[i][j]);
      } else {
        //PUT THINGS IN A SET?
        newRy.push_back(inputs[i][j]);
      }
    }
    X.push_back(newRX);
    y.push_back(newRy);
  }
  std::cout << "X: " << std::endl;
  for(int i = 0; i < X.size(); i++) {
    for(int j = 0; j < X[i].size(); j++) {
      std::cout << X[i][j] << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << "y: " << std::endl;
  for(int i = 0; i < y.size(); i++) {
    for(int j = 0; j < y[i].size(); j++) {
      std::cout << y[i][j] << ", ";
    }
    std::cout << std::endl;
  }
}
