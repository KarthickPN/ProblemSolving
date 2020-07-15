/* Leetcode problem
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
            You may assume the two numbers do not contain any leading zero, except the number 0 itself.

            EXAMPLE:

                      Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8

                     Explanation: 342 + 465 = 807.
*/

#include <iostream>
#include <forward_list>

 
std::forward_list<int> listSum(std::forward_list<int> a,  std::forward_list<int> b )
{
  std::forward_list <int> sum_list {};
 
  // Your code here
  
  // Create iterators for both lists
  std::forward_list<int>::iterator aiter = a.begin();
  std::forward_list<int>::iterator biter = b.begin();

  bool end = true;
  // Initialize carry to 0
  int carry = 0;

  while (end)
  {
    // Initialize sum to 0 every iteration.
    int sum = 0;
    // Loop until you reach the end of list A and add the value to sum for every iteration.
    if (aiter != a.end())
    {
      sum += *aiter;
      aiter++;
    }
    // Loop until you reach the end of list B and add the value to sum for every iteration.
    if (biter != b.end())
    {
      
      sum += *biter;
      biter++;
    }
    // Now sum contains the sum of the element i in A and element B.
    // Add sum and carry, if it is over 10, get the unit position by modulo 10 and find the carry by dividing by 10.
    sum_list.push_front((sum+carry)%10);
    carry = (sum+carry)/10;
    //If we have iterated through both list A and list B...
    if(aiter == a.end() && biter ==b.end())
    {
      // If the carry is still 1, add a bloody new node at the front with value 1.
      if (carry == 1) sum_list.push_front(1);
      end = false;
    }
  }
  return sum_list;

}
 
int main() {
  std::forward_list <int> list1 {1,2,3};
  std::forward_list <int> list2 {1,2,3};

  std::forward_list <int> list3 {1,2,3};
  std::forward_list <int> list4 {1,2};

  std::forward_list <int> list5 {9,9};
  std::forward_list <int> list6 {1,1};

  std::forward_list <int> list7 {9,9};
  std::forward_list <int> list8 {1};

  std::forward_list <int> list9 {1};
  std::forward_list <int> list10 {9,9};

  std::forward_list <int> list11 {9,9,9,9};
  std::forward_list <int> list12 {9,9,1,3,4,5};

  std::forward_list <int> ans = listSum(list1, list2);
  
  ans.reverse();

  for (std::forward_list<int>::iterator it = ans.begin(); it != ans.end(); it++)
  {
    std::cout << *it << " ";
  }

}