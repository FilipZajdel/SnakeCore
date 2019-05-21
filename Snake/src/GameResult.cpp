#include <iostream>
#include "../Snake.hpp"

std::tuple<int, float> GameResult::getResult(std::string keyword) {
  auto result = Results.find(keyword);

  if (Results.end() != result) {
    return result->second;
  }
#if __debug
  std::cout << "Couldn't find: " << keyword << '\n';
#endif /* __debug */
  return result->second;
}

int GameResult::addNewResult(std::string keyword,
                             int iContent,
                             float fContent) {
#if __debug
  std::cout << "Size of results (std::map) is: " << Results.size() << "\n";
#endif /* __debug */

  if (Results.find(keyword) != Results.end()) {
    return -1;
  }
#if __debug
  std::cout << "Inserting {" << keyword << " : (" << iContent << " , "
            << fContent << ")}\n";
#endif /* __debug */
  Results[keyword] = std::make_tuple(iContent, fContent);
  return 0;
}

int GameResult::updateResult(std::string keyword,
                             int iContent,
                             float fContent) {
  if (Results.find(keyword) == Results.end()) {
    return -1;
  }
#if __debug
  std::cout << "Inserting {" << keyword << " : (" << iContent << " , "
            << fContent << ")}\n";
#endif /* __debug */
  Results[keyword] = std::make_tuple(iContent, fContent);
  return 0;
}

int GameResult::getIntResult(std::string keyword) {
  auto result = Results.find(keyword);

  if (Results.end() != result) {
    return std::get<0>(result->second);
  }
#if __debug
  std::cout << "Couldn't find: " << keyword << '\n';
#endif /* __debug */
  return std::get<0>(result->second);
}
int GameResult::getFloatResult(std::string keyword) {
  auto result = Results.find(keyword);

  if (Results.end() != result) {
    return std::get<1>(result->second);
  }
#if __debug
  std::cout << "Couldn't find: " << keyword << '\n';
#endif /* __debug */
  return std::get<1>(result->second);
}