/* 
Title: Algoexpert - Array - Medium - Smallest difference between two arrays

Question:
Write a function that takes in two non-empty arrays of integers.
The function should find the pair of numbers (one from the first array, one from the second array)
whose absolute difference is closest to zero.
The function should return an array containing these two numbers,
with the number from the first array in the first position.
Assume that there will only be one pair of numbers with the smallest difference.

Sample input: [-1, 5, 10, 20, 28, 3], [26, 134, 135, 15, 17]
Sample output: [28, 26]

*/


#include <iostream>
#include <vector>
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
Bried explanation - Sort and set pointers at the front, move accordingly and update.
Time complexity - O(nlog(n) + mlog(m)), where m and n are the size arrays a and b resp.
Space complexity - O(1)
*/

std::vector<int> smallestDifference(std::vector<int> a, std::vector <int> b)
{
  //Initiliaze
  std::vector <int> ans {0,0};
  int sum = INT8_MAX;
  int currSum = sum;

  // Sort the arrays
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  // Set pointers
  auto aiter = a.begin();
  auto biter = b.begin();
  sum = abs(*aiter + *biter);

  // Start the loop
  while (aiter < a.end() && biter < b.end())
  {
    // Return if the elements are equal
    if (*aiter == *biter)
    {
      ans[0] = *aiter;
      ans[1] = *biter;
      return ans;
    }
    
    // If the value in array a is smaller, move the a's pointer
    if (*aiter < *biter) aiter++;
    // If the value in array b is smaller, move the b's pointer
    else if (*aiter > *biter) biter++;

    currSum = abs(*aiter - *biter);
    if (currSum < sum) 
    {
      sum = currSum;
      ans[0] = *aiter;
      ans[1] = *biter;
    }
  }
  printSeq(ans);
  return ans;
}

int main() {
  /*
  {0}, {0}
  {0,0,0,}, {0,0,0}
  {-1,5,10,20,28,3}, {26,134,135,15,17}
  {1,2,3,4,5}, {6,7,8,9,10}
  */
  std::vector <int> a {1,2,3,4,5};
  std::vector <int> b {6,7,8,9,10};

  std::vector <int> ans = smallestDifference(a,b);
}