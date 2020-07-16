/* Title: Leetcode - Array - Medium - 3Sum

Note: This problem is very similar to Algoexpert threeNumberSum. The only difference is - no duplicate sets of triplets even though they are from different indices. So find the explanation in the other problem.
		Example: [-1,0,-1,2,-1,-4] will have [[-1,-1,2],[-1,0,1], [-1,0,1]] as the outputs in threeNumberSum.cpp
				 In this problem the output would be [[-1,-1,2],[-1,0,1]]. 

Question:

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


/*
Solution 1
Time complexity - O(n^2) (I guess)
Space complexity - O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>


std::vector <std::vector <int> > threeNumSum(std::vector<int> input, int target)
{
    std::vector <std::vector <int> > totalOutput{};
    if (input.size() < 3) return totalOutput;
  std::sort(input.begin(), input.end());

  int currSum = INT8_MAX;
  auto currVal = input.begin();
  auto left = currVal+1;
  auto right = input.end()-1;

  auto rightOrig = right;
  for (auto i = input.begin(); i != input.end(); i++)
  {
    while(left - input.begin() < right-input.begin())
    {
      currSum = *i + *left + *right;
      if (currSum == target)
      {
        std::cout << "*i = " << *i << "*left = " << *left <<"*right = " << *right << std::endl;
        totalOutput.push_back({*i, *left, *right});
		// If there's no duplicate
		if(*left == *(left+1)) left++;
        // If there are duplicates, to remove duplicates and also to make sure we don't move the left pointer beyond the end
        while(*left == *(left+1) && left < input.end())
        {
          left++;
        }
		// If there's no duplicate
        if (*right != *(right-1)) right--;
		// If there are duplicates, to remove duplicates and also to make sure we don't move the right pointer beyond the front		
		while (*right == *(right-1) && right != input.begin())
        {
          
          right--;
        }
      }
      else if (currSum < target) left++;
      else if (currSum > target) right--;
    }
	// If there's no duplicate
	if(currVal != currVal+1) currVal++;
	// If the next value is same as the previous value, keep moving until you either hit the right value or the end.
    if(currVal != input.end())
    {
        while (*currVal == *(currVal+1))
        {
            currVal++;
        }
    }

    
    left = currVal + 1;
    right = rightOrig;
  }
  
  return totalOutput;
}


int main() {
  std::vector <int> input {-1,0,-1,2,3,-2,1};
  int target = 0;

  threeNumSum(input, target);
}