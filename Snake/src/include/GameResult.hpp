#pragma once

#include <string>
#include <map>
#include <tuple>

using std::string;
using std::map;
using std::tuple;

class GameResult {
 public:
  tuple<int, float> getResult(string keyword);
  int getIntResult(string keyword);
  int getFloatResult(string keyword);
  /** @brief Adds new element to Results. Returns 0 if succeed, -1 otherwise
   */
  int addNewResult(string = NULL, int = 0, float = 0);
  int updateResult(string = NULL, int = 0, float = 0);

 private:
  map<string, tuple<int, float>> Results;
};