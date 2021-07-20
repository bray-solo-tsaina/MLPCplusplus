#ifndef MLPCLASSIFIER_H
#define MLPCLASSIFIER_H
#include <vector>


#include <iostream>

class MLPClassifier {
  double learningRate;
  double momentum;
public:
  MLPClassifier();
  void fit(std::vector<std::vector<double>> inputs);

};


#endif
