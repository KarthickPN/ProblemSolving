#include <iostream>
#include <string>
#include <vector>
 
const std::vector<int> num_of_days {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
bool leapYear(int year)
{
  if (year%4 == 0){
    if (year%100 == 0 && year%400 == 0) return true;
    else if (year%100 != 0) return true;
  }
  return false;
}
 
void ageCalc(int byear, int bmon, int bday, int tyear, int tmon, int tday)
{
  if (bmon > tmon)
  {
    int year = tyear - byear - 1;
    int mon = 12 - bmon + tmon;
    int days = num_of_days[bmon-1] - bday + tday;
    if (days >31)
    {
      days = days - 31;
    }
    if (days == 31)
    {
      days = 0;
    }
    std::cout << "func1" << std::endl;
    std::cout << year << " " << mon << " " << days;
  }
  else
  {
    int mon = tmon - bmon;
    int year = tyear - byear;
    int days = num_of_days[bmon-1] - bday + tday;
    if (days > 31)
    {
      days = days - 31;
    }
    if (days == 31)
    {
      days = 0;
    }
    std::cout << "func2" << std::endl;
    std::cout << year << " " << mon << " " << days;
  }
}
 
int main() {
  int byear, bmon, bday, tyear, tmon, tday;
 
  std::cout << "Enter your birthday: ";
  std::cin >> byear >> bmon >> bday;
  std::cout << std::endl;
 
  std::cout << "Today: ";
  std::cin >> tyear >> tmon >> tday;
  std::cout << std::endl;
 
  ageCalc(byear, bmon, bday, tyear, tmon, tday);
}