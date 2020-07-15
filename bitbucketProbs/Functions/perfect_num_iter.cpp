#include <iostream>
 
void perfect(int number, int *sum)
{
  int stop = number/2;
  for (int i = 1; i <=stop; i++)
  {
    if(number%i == 0)
    {
      *sum += i;
    }
  }
}
 
int main()
{
  for (int number = 1; number <= 1000 ; number++)
  {
    int sum = 0;
    perfect(number, &sum);
    if (sum == number)
    {
      std::cout << "Yes! The perfect number is: " << number <<std::endl;
    }
  }
}