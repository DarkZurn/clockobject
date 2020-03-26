#pragma once
#include <map>
#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include "../splitString.h"

//#define timegm _mkgmtime
//using namespace std::literals::chrono_literals;
using namespace std::chrono_literals;

//Объект "Часы" -сингелтон
class TimeClock {
public: 
  TimeClock();
  virtual ~TimeClock(); 
  
  //Получить следующую минуту демо-времени
  const std::string & getDemoTime();
  //Получить текущее значение демо-времени
  std::string getCurrentDemoTime();
  //Прибавить один день к дате
  std::string plusDate(std::string date, int day);
  //Получить информационную дату
  std::string getNonFixedDate();
  //Управление нефиксированной датой
  std::string setNonFixedDate(int numDays);

 private:
  std::string curTime;
  std::tm timepoint_tm; //!!!
  std::time_t timepoint_time_t_1;
  std::chrono::time_point<std::chrono::system_clock> timepoint;
  std::chrono::time_point<std::chrono::system_clock> nonFixedTimepoint;
  std::string nonFixedTime;
  std::map <std::string, std::string> monthList;
  int getDaysInMonth (int month, int year);
};

//TimeClock* TimeClock ::_self = 0;


