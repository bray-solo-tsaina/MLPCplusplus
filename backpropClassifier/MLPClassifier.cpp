#include "MLPClassifier.h"
#include <math.h>

double sigmoid_fn(double x) {
  return 1 / (1 + exp(-x));
}

void MLPClassifier::sigmoid_nets(array2d<double>& x) {
  for (int i = 0; i < x.w(); i++) {
    x(0, i, sigmoid_fn(x(0, i)));
  }
}

void printArray2d(array2d<double> A) {
  std::cout << "[ ";
  for(int i = 0; i < A.h(); i++) {
    std::cout << "[ ";
    for(int j = 0; j < A.w(); j++) {
      std::cout << A(i, j) << ", ";
    }
    std::cout << " ], ";
    std::cout << std::endl;
  }
  std::cout << "]" << std::endl;
}

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
    printArray2d(weights[i]);
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

void MLPClassifier::initializeWeights(array2d<double> X, array2d<double> y) {
  int numFeatures = X.w();
  int numOutput = y.w();

  int prevLayerWidth = numFeatures + 1;

  if (this->layers[0] == -1) {
    this->layers[0] = (numFeatures) * 2;
  }

  for (int i = 0; i < this->layers.size(); i++) {
    //create new 2D layer
    // std::vector<std::vector<double>> newLayer;
    // for (int j = 0; j < prevLayerWidth; j++) {
    //   std::vector<double> newRow(layers[i], 0);
    //   newLayer.push_back(newRow);
    // }
    array2d<double> newLayer(prevLayerWidth, layers[i], 0);
    this->weights.push_back(newLayer);
    //add that to the list of weights
    prevLayerWidth = this->layers[i] + 1;
  }
  // std::vector<std::vector<double>> newLayer;
  // for (int j = 0; j < prevLayerWidth; j++) {
  //   std::vector<double> newRow(numOutput, 0);
  //   newLayer.push_back(newRow);
  // }
  array2d<double> lastLayer(prevLayerWidth, numOutput, 0);
  this->weights.push_back(lastLayer);
}

/*
  Forward input through in order to get NN output
*/
double * MLPClassifier::forward(double *x) {
  //adding bias input
  array2d<double> xinp(1, this->weights[0].h(), 1);
  for (int i = 0; i < xinp.w() - 1; i++) {
    xinp(0, i, x[i]);
  }
  this->outputs.push_back(xinp);
  array2d<double> currInp = xinp;

  for (int i = 0; i < this->weights.size(); i++) {
    array2d<double> nets = currInp * this->weights[i];
    sigmoid_nets(nets);

    if(i != this->weights.size() - 1) { //adding bias to all but final layer
      array2d<double> nnets(1, nets.w() + 1, 1);
      for (int i = 0; i < nets.w(); i++) {
        nnets(0, i, nets(0, i));
      }
      this->outputs.push_back(nnets);
      currInp = nnets;
    } else {
      this->outputs.push_back(nets);
      currInp = nets;
    }
  }

  // std::cout << "OUPTPUTS:"<< std::endl;
  // for(int i = 0; i < this->outputs.size(); i++) {
  //   std::cout << std::endl;
  //   printArray2d(this->outputs[i]);
  // }

  return this->outputs[this->outputs.size() - 1](0);
}

void MLPClassifier::backward(double *output, double *y) {
  std::vector<array2d<double>> partials;
  array2d<double> partial(1, this->outputs[this->outputs.size() - 1].w(), 0);
  for(int i = 0; i < partial.w(); i++) {

  }
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
  array2d<double> X(inputs.size(), inputs[0].size() - 1, 0);
  array2d<double> Y(inputs.size(), 1, 0);


  for (int i = 0; i < inputs.size(); i++) {
    for (int j = 0; j < inputs[i].size(); j++) {
      if (j != inputs[i].size() - 1) {
        X(i, j, inputs[i][j]);
      } else {
        //PUT THINGS IN A SET?
        Y(i, 0, inputs[i][j]);
      }
    }
  }
  std::cout << "X: " << std::endl;
  printArray2d(X);
  std::cout << "y: " << std::endl;
  printArray2d(Y);

  initializeWeights(X, Y);
  printWeights();


  //CURRENTLY JUST 1 EPOCH
  int numEpochs = 1;
  for (int i = 0; i < numEpochs; i++) {
    for (int j = 0; j < X.h() - 1; j++) { //TODO: DELETE THE - 1
      std::cout << "CURRENT WEIGHTS" << std::endl;
      printWeights();
      double *xrow = X(j);
      double *yrow = Y(j);
      // std::cout << "XROW\n[ ";
      // for(int i = 0; i < X.w(); i++) {
      //   std::cout << xrow[i] << ", ";
      // }
      // std::cout << "]" << std::endl;


      double *output = forward(xrow);
      std::cout << "OUTPUT\n[ ";
      for(int i = 0; i < Y.w(); i++) {
        std::cout << output[i] << ", ";
      }
      std::cout << "]" << std::endl;

      backward(output, yrow);
    }
  }
}
