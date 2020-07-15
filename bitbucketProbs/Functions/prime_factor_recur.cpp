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
 
void factor(int number, int i)
{
  if (i <= number/2)
  {
    if (number%i == 0 && prime(i))
    {
        std::cout << i << std::endl;
    }
    i++;
    factor(number, i);
  }
}
 
int main() {
  const int number = 510510;
  int i = 2;
  factor(number, i);
}