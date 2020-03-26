#include "singClock.h"

//Объект "Часы" -сингелтон
TimeClock* TimeClock ::_self = 0;
//Конструктор 
TimeClock::TimeClock() {  
  //Месяца
  monthList["Jan"] = "01";
  monthList["Feb"] = "02";
  monthList["Mar"] = "03";
  monthList["Apr"] = "04";
  monthList["May"] = "05";
  monthList["Jun"] = "06";
  monthList["Jul"] = "07";
  monthList["Aug"] = "08";
  monthList["Sep"] = "09";
  monthList["Oct"] = "10";
  monthList["Nov"] = "11";
  monthList["Dec"] = "12";
  //timepoint += std::chrono::hours(428889);
  timepoint += std::chrono::hours(420873);
  nonFixedTimepoint += std::chrono::hours(420873);
}

//Получить следующую минуту демо-времени
const std::string & TimeClock::getDemoTime() {       
  std::time_t timepoint_time_t_2 = std::chrono::system_clock::to_time_t(timepoint);
  curTime = ctime(&timepoint_time_t_2);
  curTime = curTime.substr(0, 24);
  timepoint += 1min;
  return curTime;
}

//Получить нефиксированную дату
std::string TimeClock::getNonFixedDate() {
  std::time_t timepoint_time_t_3 = std::chrono::system_clock::to_time_t(nonFixedTimepoint);
  std::vector<std::string> fDateTime = split(ctime(&timepoint_time_t_3), " ");
  return fDateTime[2] + "." + monthList[fDateTime[1]] + "." + fDateTime[4];  
}

//Управление нефиксированной датой
std::string TimeClock::setNonFixedDate(int numDays) {
  nonFixedTimepoint += (24h * numDays);
  return this->getNonFixedDate();
}


//Получить текущее значение демо-времени
std::string TimeClock::getCurrentDemoTime(){
  return curTime;
}

int TimeClock::getDaysInMonth (int month, int year) {
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  } else if (month == 2) {
    if (year%4 != 0 || year%100 == 0 && year%400 != 0) {    //Весокосный  
      return 28;
    } else {
      return 29;
    }
  } else {
    return 31;
  }   
}

std::string TimeClock::plusDate(std::string date, int dayPlus) {
  if(dayPlus < 0) {
    exit(1);
  }
  int day = atoi(date.substr(0, 2).c_str());
  int month = atoi(date.substr(3, 2).c_str());
  int year = atoi(date.substr(6, 4).c_str());
  //Число дней в месяце
  int daysInMonth = getDaysInMonth (month, year);  
  //Прибавляем день
  day += dayPlus;
  while (day > daysInMonth) {
    day -= daysInMonth;
    month++;
    if (month > 12) {
      month = 1;
      year++;
    }
    daysInMonth = getDaysInMonth (month, year);
  }
  std::string strDay;
  std::string strMonth;  
  //Собираем дату назад
  if(day < 10) {
    strDay = "0" + std::to_string(day);
  } else {
    strDay = std::to_string(day);
  }
  if(month < 10) {
    strMonth = "0" + std::to_string(month);
  } else {
    strMonth = std::to_string(month);
  }
  return strDay + "." + strMonth + "." + std::to_string(year);
}
