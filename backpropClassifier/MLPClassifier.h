#ifndef MLPCLASSIFIER_H
#define MLPCLASSIFIER_H
#include <vector>

#include <iostream>
#include "../array2d/array2d.h"

class MLPClassifier {
  double learningRate;
  double momentum;


  std::vector<int> layers;

  //HOW BEST TO STORE? array of ARRAY2D OBJECTS?
  std::vector<array2d<double>> weights;
  std::vector<array2d<double>> prevweights;

  std::vector<array2d<double>> outputs;

  void initializeWeights(array2d<double> X, array2d<double> y);
  double * forward(double *x);
  void backward(double *output, double *y);

  void sigmoid_nets(array2d<double>& x);

  //DEBUGGING
  void printNestedVector(std::vector<std::vector<double>> inp);
  void printWeights();


public:
  MLPClassifier(const std::vector<int>& layers = std::vector<int>());
  void fit(std::vector<std::vector<double>> inputs);

};


#endif
