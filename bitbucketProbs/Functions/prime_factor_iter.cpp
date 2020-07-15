#include <iostream>
 
bool prime(int number)
{
  int count = 0;
  for(int i = 1; i <= number; i++)
  {
    if(count < 3 && number % i == 0)
    {
      count++;
    }
  }
  if (count == 2) return true;
  return false;
}
 
void factor(int number)
{
  for (int i = 2; i <= number/2; i++)
  {
    if (number%i == 0 && prime(i))
    {
        std::cout << i << std::endl;
    }
  }
}
 
int main() {
  const int number = 100;
  factor(number);
}