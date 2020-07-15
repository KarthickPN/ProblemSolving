include <iostream>
#include <list>
#include <string>
#include <algorithm>
 
void print(std::list <std::string> planets)
{
  for (auto it = planets.begin(); it != planets.end(); it++)
  {
    std::cout<< *it <<std::endl;
  }
  std::cout << "------" << std::endl;
}

int main() {
  std::list <std::string> planets {"Earth", "Venus", "jupiter", "Uranus", "Uranus"};
 
  // 1. Add "Mercury" to start of the list
  planets.push_front("Mercury");
  //std::cout <<"1. Added mercury" << std::endl;
  //print(planets);
 
  // 2. Add "Neptune" to the end of the list
  planets.push_back("Neptune");
  //std::cout <<"2. Added Neptune" << std::endl;
  //print(planets);
 
  // 3. Swap the places of "Earth" and "Venus"
  std::list <std::string>::iterator iter = planets.begin();
  std::iter_swap(++iter, ++iter);
  //std::cout <<"3. Swapped Earth and Venus" << std::endl;
  //print(planets);
 
  // 4. There are 2 "Uranus". Remove duplicates.
  // std::unique(planets.begin(), planets.end());
  // Note - The above doesn't work - Deletes only the value in that node, but the pointer which points to next node still exists - I guess.
  planets.unique();
  //std::cout <<"4. Removed Uranus" << std::endl;
  //print(planets);
 
  // 5. Insert the remaining missing planets in their respective places
  //std::cout <<"5. Inserted remaining missing planets" << std::endl;
  std::list <std::string>::iterator iter2 = std::find(planets.begin(),planets.end(), "jupiter");
  planets.insert(iter2, "Mars");
  planets.insert(++iter2, "Saturn");
  //print(planets);
 
  // 6. Return the total number of elements in the list.
  //std::cout <<"6. Size" << std::endl;
  int size = planets.size();
  //print(planets);
  //std::cout << "Size = " << size << std::endl;
  //std::cout << "------" << std::endl;
 
  // 7. Make a separate list of planets that start with alphabet "M"
  //std::cout <<"7. Separate list for planets that start with M" << std::endl;
  std::list <std::string> M_planets {};
  for (auto iter3 = planets.begin(); iter3 != planets.end(); iter3++)
  {
    if ((*iter3).find("M",0) == 0)
    {
      M_planets.push_back(*iter3);
    }
  }
  //print(M_planets);

  // 8. Reverse the list completely.
  planets.reverse();
  //std::cout <<"8. Reverse list" << std::endl;
  //print(planets);
 
  // 9. Append the following list to the planets list.
  //std::cout <<"9. Appended Pluto list" << std::endl;   
  // Note - list1.merge(list2) doesn't work. The items in list2 insert themselves in sorted order in list 1.
  std::list <std::string> lonely_planet {"Pluto"};
  planets.splice(planets.begin(),lonely_planet);
  //print(planets);
  
  // 10. The next operation is sorting. But before that, "jupiter" starts with lowercase "j", so replace "jupiter" with "Jupiter".
  //std::cout <<"10. Replaced jupiter" << std::endl;
 replace(planets.begin(), planets.end(), "jupiter", "Jupiter");
 //print(planets);

  // 11. Sort the planets on alphabetical order and print the sorted list.
  //std::cout <<"11. Sorted" << std::endl;
  // std::sort(planets.begin(), planets.end())
  // Note - The above doesn't work for lists - I guess
  planets.sort();
  print(planets);
}