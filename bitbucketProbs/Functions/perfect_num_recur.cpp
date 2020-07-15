#include <iostream>
  
void perfect(int number, int i, int *p)
{
  if (i<=number/2)
  {
    if (number % i == 0)
    {
      *p += i;
    }
  i++;
  perfect(number, i, p);
  }
}
  
int main()
{
  int num = 1;
  int i = 1;
  while (num <= 1000)
  {
    int sum = 0;
    perfect(num, &sum);
    if (sum == num)
    {
      std::cout << "The number is = " << sum << std::endl;
    }
    num++;
  }
}