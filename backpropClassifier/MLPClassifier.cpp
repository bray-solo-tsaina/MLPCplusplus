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

void MLPClassifier::initializeWeights(std::vector<std::vector<double>> X, std::vector<std::vector<double>> y) {
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
}

/*
  Forward input through in order to get NN output
*/
std::vector<double> MLPClassifier::forward(std::vector<double> x) {
  //Add bias input
  x.push_back(1);
  std::vector<std::vector<double>> outputs;
  outputs.push_back(x);

  for (int i = 0; i < this->weights.size(); i++) {
    std::vector<std::vector<double>> MMul(outputs[outputs.size() - 1], this->weights[i])
  }






  //Remove bias input (just so future epochs don't have multiple biases)
  x.pop_back();
  return p;
}



/*
  MAIN FIT FUNCTION CALLED BY USER
    Seperates input into X (training features)
                    and y (training targets)

    Initializes Weights by using the private method
    Then for each row of input
      forwards input through net
      Error gets put backward through net
      Applies gradient descent

    CURRENTLY:
      Does so for 1 epoch (WIP!)

*/


void MLPClassifier::fit(std::vector<std::vector<double>> inputs) {
  std::vector<std::vector<double>> X;
  std::vector<std::vector<double>> Y;
  for (int i = 0; i < inputs.size(); i++) {
    std::vector<double> newRX;
    std::vector<double> newRY;
    for (int j = 0; j < inputs[i].size(); j++) {
      if (j != inputs[i].size() - 1) {
        newRX.push_back(inputs[i][j]);
      } else {
        //PUT THINGS IN A SET?
        newRY.push_back(inputs[i][j]);
      }
    }
    X.push_back(newRX);
    Y.push_back(newRY);
  }
  std::cout << "X: " << std::endl;
  printNestedVector(X);
  std::cout << "y: " << std::endl;
  printNestedVector(Y);

  initializeWeights(X, Y);

  //CURRENTLY JUST 1 EPOCH
  int numEpochs = 1;
  for (int i = 0; i < numEpochs; i++) {
    for (int j = 0; j < X.size() - 1; j++) {
      std::cout << "CURRENT WEIGHTS" << std::endl;
      printWeights();
      std::vector<double> x = X[j];
      std::vector<double> y = Y[j];

      std::vector<double> output = forward(x);
    }
  }
}
