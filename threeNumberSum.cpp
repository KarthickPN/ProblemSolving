/* Title: AlgoExpert - Array - Medium - Three Number Sum

Question:
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum.
The function should find all triplets in the array that sum up to the target sum and
return a two-dimensional array of all these triplets.
The numbers in each triplet should be ordered in ascending order,
and the triplets themselves should be ordered in ascending order with respect to the numbers they hold.
If no three numbers sum up to the target sum, the function should return an empty array.

Sample input: [12, 3, 1, 2, -6, 5, -8, 6], 0
Sample output: [[-8, 2, 6], [-8, 3, 5], [-6, 1, 5]]

*/

#include <iostream>
#include <vector>
#include <algorithm>

/*
Solution 1
Detailed explanation - Sort the array, "fix" a pointer1 to the first val. Set leftPointer and righttPointer in start and end resp. Move the latter two pointers based on the sum of all the 3 pointers.
						When the latter two pointers cross each other break the loop and move the pointer1 to next element. Put left pointer to one element after the pointer1 and right pointer to the last element.
							Continue the loop.
Time complexity - O(n^2) 
Space complexity - O(n)
*/

std::vector <std::vector <int> > threeNumSum(std::vector<int> input, int target)
{
    std::vector <std::vector <int> > totalOutput{};
    // If the input is less than 3 values, return empty vector.
	if (input.size() < 3) return totalOutput;
	// Sort the array
	std::sort(input.begin(), input.end());
	
	int currSum = INT8_MAX;
	auto currVal = input.begin();
	auto left = currVal+1;
	auto right = input.end()-1;
	auto rightOrig = right;
	
	// Pointer1
	for (auto i = input.begin(); i != input.end(); i++)
	{	
		// For the fixed pointer1, move left and right pointers accordingly.
		while(left - input.begin() < right-input.begin())
		{
		// Calculate current sum
		currSum = *i + *left + *right;
		// If they are equal, push to the output vector and move both left and right pointers one location.
		if (currSum == target)
		{
			std::cout << *i << " | " << *left << " | " << *right << std::endl;
			totalOutput.push_back({*i, *left, *right});
			left++;
			right--;   

      
		}
		// Move only left if the current sum is less than target sum
		else if (currSum < target) left++;
		// Move only right if the current sum is greater than target sum
		else if (currSum > target) right--;
		}
      
		// Move pointer1 one element.
		currVal++;
		// Re-initialize left and right pointers
		left = currVal + 1;
		right = rightOrig;
  }
  
  return totalOutput;
}


int main() {
  std::vector <int> input1 {0,0,0};
  std::vector <int> input2 {0};
  std::vector <int> input3 {-1,0,1,2,-1,-4};
  std::vector <int> input4 {-8,-6,1,2,3,5,6,12};
  
  int target = 0;

  threeNumSum(input, target);
}