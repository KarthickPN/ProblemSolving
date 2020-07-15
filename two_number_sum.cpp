/* 
Title: Algoexpert - Array - Easy - Two Number Sum

Question:
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum.
If any two numbers in the input array sum up to the target sum, the function should return them in an array.
If no two numbers sum up to the target sum, the function should return an empty array.
Assume that there will be at most one pair of numbers summing up to the target sum.

Sample input: [3, 5, -4, 8, 11, 1, -1, 6], 10
Sample output: [-1, 11]

*/

#include <iostream>
#include <vector>
#include <unordered_map> 
#include <algorithm>

// Generic print function for sequential containers.
template <typename T>
void printSeq(T x)
{
  for (auto i = x.begin(); i != x.end(); i++)
  {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

/*
Solution 1
Bried explanation - Double for loops
Time complexity - O(n^2) 
Space complexity - O(1)
*/
std::vector <int> twoNumberSum1(std::vector <int> input, int target)
{
  std::vector <int> output {};
  int sum = 0;

  for(auto i = input.begin(); i != input.end(); i++)
  {
    for (auto j = input.begin(); j!= input.end(); j++)
    {
      /* To make sure the algorithm doesn't add the numbers from same index twice.
         The following line essentially means, go into for loop only when index j is        different from i*/
      if(i - input.begin() != j - input.begin()) 
      
      {
        sum = *i + *j;
        if (sum == target)
        {
          output.push_back(*i);
          output.push_back(*j);
          return output;
        }
      }
    }
  }
  
  return output;
}

/*
Solution 2
Brief explanation - Sort and use two pointers, one at front and one at the end - move iteratively (and accordingly) based on the sum.
Time complexity - O(n*log(n)) 
Space complexity - O(1)
*/
std::vector <int> twoNumberSum2(std::vector <int> input, int target)
{
  std::vector <int> output {};
  std::sort(input.begin(), input.end());
  // Can't initalize to 0, cos the loop wouldn't work if the target is also 0.
  int sum = INT8_MAX;
  
  // Set the pointers
  auto i = input.begin();
  auto j = input.end();
  --j;
  
  // Start looping
  while(sum != target)
  {
    sum = *i+*j;
    // When the pointers meet, declare that no value was found and return
    if (i - input.begin() == j - input.begin())
    {
      return output;
    }
    
    // If sum is less, move the left pointer
    if (sum < target)
    {
      ++i;
      sum = INT8_MAX;
    }
    // If the sum is greater, move the right pointer.
    else if (sum >target)
    { 
      --j;
      sum = INT8_MAX;
    }
    // If sum equals, push the i and j values to the output array.
    if (sum == target)
    {
      output.push_back(*i);
      output.push_back(*j);
    }
  }
  return output;
}

/*
Solution 3
Brief explanation - Use hash table (unordered map).
Time complexity - O(n) 
Space complexity - O(n)
*/

std::vector <int> twoNumberSum3(std::vector <int> input, int target)
{
  std::vector <int> output {};
  std::unordered_map<int, bool> inputTable;
  
  for (auto i=input.begin(); i != input.end(); i++)
  { 
    // If the value x = target - *i is present in the hash table already, push them and return
    if (inputTable[target-*i])
    {
      output.push_back(*i);
      output.push_back(target-*i);
      return output;
    }
    // Otherwise add the value to the hash table
    else
    {
      inputTable[*i] = true;
    }

  }
  return output;
}


int main() {
  std::vector <int> input1 {3, -5, -4, 8, 11, 1, -1, 6};
  std::vector <int> input2 {5,5};
  std::vector <int> input3 {};
  std::vector <int> input4 {1};

  int target = 10;

  std::vector <int> output = twoNumberSum3(input2, target);

  printSeq(output);

  // TODO - input2 on solution 2 throws segmentation fault. Fix it.
}