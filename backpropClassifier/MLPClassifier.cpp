#include "MLPClassifier.h"

MLPClassifier::MLPClassifier(const std::vector<int>& layers) {
  this->learningRate = 0.1;
  this->momentum = 0;
  if (layers.size() == 0) {
    this->layers = {-1};
  } else {
    this->layers = layers;
  }
}

void MLPClassifier::printWeights() {
  for (int i = 0; i < this->weights.size(); i++) {
    std::cout << std::endl;
    std::cout << "[ ";
    printNestedVector(weights[i]);
    std::cout << " ]";
    std::cout << std::endl;
  }
}

void MLPClassifier::printNestedVector(std::vector<std::vector<double>> inp) {
  for(int i = 0; i < inp.size(); i++) {
    std::cout << "[ ";
    for(int j = 0; j < inp[i].size(); j++) {
      std::cout << inp[i][j] << ", ";
    }
    std::cout << " ]";
    std::cout << std::endl;
  }
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
  printNestedVector(X);
  std::cout << "y: " << std::endl;
  printNestedVector(y);


  int numFeatures = X[0].size();
  int numOutput = 1; //TODO CURRENTLY ONLY DEALING WITH BINARY CLASSIFICATION (1 or 0)

  int prevLayerWidth = numFeatures + 1;

  if (this->layers[0] == -1) {
    this->layers[0] = (numFeatures) * 2;
  }

  for (int i = 0; i < this->layers.size(); i++) {
    //create new 2D layer
    std::vector<std::vector<double>> newLayer;
    for (int j = 0; j < prevLayerWidth; j++) {
      std::vector<double> newRow(layers[i], 0);
      newLayer.push_back(newRow);
    }
    this->weights.push_back(newLayer);
    //add that to the list of weights
    prevLayerWidth = this->layers[i] + 1;
  }
  std::vector<std::vector<double>> newLayer;
  for (int j = 0; j < prevLayerWidth; j++) {
    std::vector<double> newRow(numOutput, 0);
    newLayer.push_back(newRow);
  }
  this->weights.push_back(newLayer);

  printWeights();
}
