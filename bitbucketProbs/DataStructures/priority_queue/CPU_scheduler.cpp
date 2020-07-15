/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.



Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.


Constraints:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100]
-------------------------------------------------------------------------------------------

Notes:
1. The best case is Input - ABCDEF, n=2 -> ABCDEF | ans = 6.
2. The worst (probably) case is Input - AAAAAA, n=2 -> AiiAiiAiiAiiAiiA | ans = 16
3. For all the other cases, just populate the task with max elements and interval first,  and then insert other tasks. Example,
      AAAABB, n=2
      Step 1: Aii Aii Aii A
      Step 2: AiB AiB Aii A | ans = 10
4. What does this mean?
    Irrespective of other elements, the CPU is going to perform tasks 
    max_val * (max_val - 1) times  ------> INITIAL LOGIC
5. SPECIAL CASE - Took hours to find!!!!!!
    When the max_val_count appears more than once, like the following
      AAABBB, n=2
    Step 1: Take any one of the max_val element and insert with intervals 
            Aii Aii A
    Step 2: Inser the other element 
            AiB AiB AB
            So what happens here is, if there are 2 max_vals, value 1 is added to the logic
            If there are 3 max_vals, value 2 is added to the logic.
            So add max_val_count - 1 to the initial logic.
    
The final Logic ---> max_val * (max_val - 1) + (max_val_count - 1) 
*/



#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
 
void printMap(std::unordered_map<char, int>& inputMap)
{
  std::cout << "The hash table" << std::endl;
  for (auto [chr, counts] : inputMap)
  {
    std::cout << chr << " = " << counts << std::endl;
  }
}
 
int scheduler(std::vector <char>& tasks, int n)
{
  // 1. Find the count of each type of task by inserting them into a map
  std::unordered_map <char, int> count{};
  
  
 
  for (auto it = tasks.begin(); it != tasks.end(); it++)
  {
    if (count.find(*it) == count.end())
    {
      count[*it] = 1;
    }
    else {
      count[*it] += 1;
    } 
  }
printMap(count);
 
//---------------Priority Queue Implementation---------------//
  // 2. Insert everything into the priority queue to have the max_element at the beginning.
 std::priority_queue<int> answers;
 for (auto [chr, num] : count)
  {
    answers.push(num);
  }
  int max_val = answers.top();
  
  // 3. Count the number of times the max element is present in the priority queue
  int max_val_count = 0;
  do{
    max_val_count++;
    answers.pop();
  } while (!answers.empty() && answers.top() == max_val);


//---------------Vector Implementation---------------//
 
  /*std::vector <int> answers;

  for (auto [chr, num] : count)
  {
    answers.push_back(num);
  }

  std::sort(answers.begin(), answers.end(), std::greater<int>());
   
  int max_val = *std::max_element(answers.begin(), answers.end());

  int max_val_count = std::count(answers.begin(), answers.end(), max_val);*/
  
  // 4. This is the logic.
  return max_val + (max_val - 1)*n + (max_val_count-1);
}
 
int main() {
  std::vector <char> tasks1 = {'A', 'B', 'C', 'D', 'E', 'F'};
  std::vector <char> tasks2 = {'A', 'A', 'A', 'B', 'B', 'B'};
  std::vector <char> tasks3 = {'A', 'A', 'A', 'A', 'A'};
  std::vector <char> tasks4 = {'A', 'A', 'A', 'B', 'B', 'C'};
  std::vector <char> tasks5 = {'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'D'};
  std::vector <char> tasks6 = {'A', 'A', 'B', 'C', 'D'};
  std::vector <char> tasks7 = {'A', 'A', 'B', 'B'};
  std::vector <char> tasks8 = {'A', 'A', 'A', 'A', 'B', 'B'};
   
  int n1 = 1;
  int n2 = 2;
  int n3 = 3;
  int n4 = 4;
  int n5 = 5;
 
  int ans = scheduler(tasks8, n2);
  std::cout << "\nThe answer is " << ans;
}