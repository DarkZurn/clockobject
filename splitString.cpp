#include "splitString.h"


//Разбивает строку  на массив подстрок по разделителю
std::vector <std::string> split(const std::string &s1, const std::string &delimiter) {
  std::vector <std::string>stringArr;
  std::string s = s1;
  //std::string delimiter = " ";
  size_t pos = 0;
  std::string token;
  size_t elem = 0;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);    
    stringArr.push_back(token);    
    s.erase(0, pos + delimiter.length());
  }
  stringArr.push_back(s); //Последняя часть строки
  return stringArr;
}
