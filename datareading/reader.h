#ifndef READER_H
#define READER_H
#include <string>
#include <vector>

class reader {
  std::string filename;

public:
  reader();
  reader(std::string filename);
  std::vector<std::vector<double>>readFile();
  std::string getFilename() {return this->filename;};
};

#endif
