#include <iostream>
 
void reverse(int *num)
{
  int store, ans = 0;
 
  while (*num!=0)
  {
    store = (*num % 10);
    ans = (ans * 10) + store;
    *num = *num/10;
  }
  *num = ans;
}
 
int main() {
  int num = 1234;
  reverse(&num);
  std::cout << num << std::endl;
}