/*
	Given an array of integers, print all sub-arrays with given sum
	
	For example
	1. Input {4, 2, -3, -1, 0, 4 }, sum = 0
	
		Sub arrays with 0 sum are
	
		{ -3, -1, 0, 4 }
		{ 0 }
	
	2. Input {3,4,-7,1,3,3,1,-4}, sum = 7
	
		Sub arrays with 7 sum are
	
		{ 3, 4}
		{ 3, 4, -7, 1, 3, 3}
		{ 1, 3, 3}
		{ 3, 3, 1}
	
*/


#include <iostream>
#include <vector>

void zeroSumSubArrays(std::vector <int>& arr, int givenSum)
{
  
  for (int i=0; i<arr.size(); i++)
  {
    // Equate sum to the first element of every iteration
    int sum = arr[i];
    // If sum is already equal to the given sum, print.
    if (sum==givenSum)
    {
      std::cout << "{ " << arr[i] << " }" << std::endl;
    }
    /* Even if the sum was equal to the given sum or not in the previous step, keep  
        continuing to find other sub arrays that follows.
       Fixing i to an element, increment j from i+1 to end of the array and increment sum.*/
    for (int j=i+1; j<arr.size(); j++)
    {
      sum = sum + arr[j];
      // If sum is equal to given sum, print the elements.
      if (sum==givenSum)
      {
        std::cout << "{"; // Aesthetics
        // For printing, start from i-th element until j
        for (int k=i; k<=j; k++)
        {
          std::cout << " " << arr[k];
          if (k!=j) std::cout << ","; // Aesthetics
        }
        std::cout << "}" << std::endl; // Aesthetics
      }
    }
  }
}

int main() {
  std::vector <int> arr {0, 0, 0, 1, -1, 4, 2, -3, -1, 0, 4};
  std::vector <int> arr1 {3,4,-7,7,-4,-3,1,3,3,1,-4};
  int sum = 7;
  zeroSumSubArrays(arr1, sum);
}