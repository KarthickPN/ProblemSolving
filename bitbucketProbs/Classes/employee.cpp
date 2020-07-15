#include <iostream>
 
class Employee{
  private:
    int F_salary;
    int AddSal(int salary);
    int AddWork(int salary, int hours);
  public:
    void getInfo(int salary, int hours);
};
 
int Employee::AddSal(int salary)
{
  if (salary < 500) salary += 10;
  return salary;
}
 
int Employee::AddWork(int salary, int hours)
{
  if (hours < 6) salary += 5;
  return salary;
}
 
void Employee::getInfo(int salary, int hours)
{
  F_salary = AddSal(salary);
  F_salary = AddWork(F_salary, hours);
  std::cout << F_salary << std::endl;
}
 
int main() {
  Employee emp1;
  emp1.getInfo(400, 5);
}