#include <iostream>
#include <string>
#include <vector>
#include <numeric>

//----------- Class Marks------------
class Marks {
  private:
    const std::string name; 
    int numStudents; // Total number of students in the class
    float tot_total; // Find the total of all the subjects combined i.e. (P+C+M) of entire class
  protected:
    int rollNumber;
  public:
    int ind_marks; 
    std::vector <float> marks; 
    
    Marks();
    float tot_marks(std::vector <float>& marks);
    float classAverage(int& students);
};

// Constructor
Marks::Marks()
  : marks {0,0,0},
    tot_total {0}
{}

// Method to find the total marks of a student
float Marks::tot_marks (std::vector <float>& marks) 
{
   float total = std::accumulate(marks.begin(), marks.end(), 0);
   tot_total += total;
   return total;
}

// Method for class average
float Marks::classAverage(int& students) 
{
  numStudents = students;
  return tot_total/students;
}
/* ---------------------------------------------------------------------------------- */

//----------- Class Physics------------
class Physics :public Marks {
  public:
    Physics(int roll){
      roll = 1000 + roll;
      std::cout << std::endl<< "---Roll Number: " << roll <<"---" <<std::endl;
    }
    float phyMark()
    {
      std::cout << "Physics mark: ";
      std::cin>> ind_marks;
      return ind_marks;
    }
};

//----------- Class Chemistry------------
class Chemistry :public Marks {
    public:
      float chemMark()
      {
      std::cout << "Chemistry mark: ";
      std::cin>> ind_marks;
      return ind_marks;
      }

};

//----------- Class Maths------------
class Maths :public Marks {
  public:
    float mathMark()
    {
      std::cout << "Maths mark: ";
      std::cin>> ind_marks;
      return ind_marks;
    }
};


int main() {

  int numStudents;
  std::cout << std::endl << "Number of students in the class: ";
  std::cin >> numStudents;
  
  // Instantiate Marks class
  Marks stu;

  for (int i = 1; i <= numStudents; i++)
  {
    // Instantiate Physics class dynamically
    Physics *phy = new Physics(i);
    float phyMark = phy->phyMark();
    stu.marks[0] = phyMark;
    delete phy;
    
    // Instantiate Chemistry Class dynamically
    Chemistry *chem = new Chemistry;
    float chemMark = chem->chemMark();
    stu.marks[1] = chemMark;
    delete chem;
    
    // Instantiate Maths Class dynamically
    Maths *math = new Maths;
    float mathMark = math->mathMark();
    stu.marks[2] = mathMark;
    delete math;

    // Total of each student
    float total = stu.tot_marks(stu.marks);
    std::cout << "Total marks of student " << i << " is: " << total << std::endl;
  }
  // Average of the entire class, all the subjects combined.
  float b = stu.classAverage(numStudents);
  std::cout << "\n\nAVERAGE TOTAL OF THE CLASS: " << b;
}