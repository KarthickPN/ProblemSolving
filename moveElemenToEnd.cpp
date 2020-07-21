/*
Move Element To End
You are given an array of integers and an integer.
Write a function that moves all instances of that integer in the array to the end of the array.
The function should perform this in place and does not need to maintain the order of the other integers.
Sample input: [2, 1, 2, 2, 2, 3, 4, 2], 2
Sample output: [1, 3, 4, 2, 2, 2, 2, 2] (the numbers 1, 3, and 4 could be ordered differently)
*/


#include <iostream>
#include <vector>

// Prints the vector
template <typename T> 
void printContainer(T x) 
{ 
   for (auto i=0; i<x.size(); i++)
   {
     std::cout << x[i] << " ";
   }
   std::cout << std::endl;
}

std::vector <int> moveElementsToEnd(std::vector <int> input, int element)
{
  if (input.size()==0) return input;
  auto p1 = 0;
  auto p2 = input.size()-1;
  int swap;
  while(p1 < p2)
  {
    if (input[p1] == input[p2] && input[p1] == element)
    {
      p2--;
    }
    else if (input[p1]==element && input[p2] != element)
    {
      swap = input[p1];
      input[p1] = input[p2];
      input[p2] = swap;
    }
    else if (input[p1] != input[p2] && input[p2] == element)
    {
      p1++;
      p2--;
    }
    else if (input[p1] != input[p2] && input[p1] != element && input[p2] != element)
    {
      p1++;
    }
  }
  return input;
}
std::vector <int> moveElementsToEnd(int a, std::vector <int> input, int element)
{
  if (input.size() == 0 || input.size() == 1) return input;
  auto p1 = 0;
  auto p2 = 1;
  int swapCount = 0;
  int moveCount = 0;
  while (p2 != input.size()-1)
  {
    if (input[p1]==element && input[p2]!= element)
    {
      input[p2-moveCount+swapCount-1] = input[p2];
      input[p2] = element;
      swapCount++;
      p1++;
      p2++;
      moveCount++;
    }
    else
    {
      p1++;
      p2++;
      moveCount++;
    }
  }
  return input;
}

int main() {
  std::vector <int> inputArray {1,2,1,1,1,1,1,1,1};
  int element = 2;
  printContainer(inputArray);
  std::vector <int> output = moveElementsToEnd(inputArray, element);
  printContainer(output);
}