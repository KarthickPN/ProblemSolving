/* Title: Leetcode - Strings - Easy - Is Subsequence?

Given a string s and a string t, check if s is subsequence of t.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:

0 <= s.length <= 100
0 <= t.length <= 10^4
Both strings consists only of lowercase characters.

*/

#include <iostream>
#include <string>

/*
Solution 1
Bried explanation - Just loop through and see if the characters in the input string match the ones in the target string.
Time complexity - O(n) 
Space complexity - O(1)
*/

bool isSubsequence(std::string s, std::string t) {
  int siz = 0;
  // Empty string - return true
  if (s.size() == 0) return true;
  // Start looping
  for (auto i = t.begin(); i != t.end(); i++)
  {
    // Loop until siz equals the target string size
    if (siz <= s.size()-1)
    {
      // If the particular character matches the character in the target string, increment siz
      if(*i == s[siz])
      { 
        siz++;
        // If the size of target string and siz are equal, return true.
        if (siz == s.size()) return true;
      }
    }
  }
  return false;
}

int main() {
  std::string str1 = {"karthick"};
  std::string str2 = {"k"};

  std::string findIn1 = {"k"};
  std::string findIn2 = {"kar"};
  std::string findIn3 = {"kra"};
  std::string findIn4 = {""};
  std::string findIn5 = {"a"};

  std::cout << isSubsequence(findIn5, str2);
}