#ifndef MLPCLASSIFIER_H
#define MLPCLASSIFIER_H
#include <vector>


#include <iostream>

class MLPClassifier {
  double learningRate;
  double momentum;


  std::vector<int> layers;
  std::vector<std::vector<std::vector<double>>> weights;


  //DEBUGGING
  void printNestedVector(std::vector<std::vector<double>> inp);
  void printWeights();


public:
  MLPClassifier(const std::vector<int>& layers = std::vector<int>());
  void fit(std::vector<std::vector<double>> inputs);

};


#endif
