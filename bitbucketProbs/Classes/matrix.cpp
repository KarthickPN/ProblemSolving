#include <iostream>
#include <vector>
 
class Matrix {
private:
  int row, col;
  std::vector<std::vector<int>> matrix;
public:
  Matrix(int r, int c);
  int rows();
  int columns();
  void set_val(int i, int j, int val);
  void add(Matrix b);
  void multiply(Matrix b);
 
};
 
Matrix::Matrix(int r, int c)
{
  row = r;
  col = c;
  std::vector<std::vector<int>> init(r, std::vector<int> (c,0));
  matrix = init;
 
}
 
int Matrix::rows() { return row; }
int Matrix::columns() { return col; }
 
void Matrix::set_val(int i, int j, int val)
{
  matrix[i-1][j-1] = val;
}
 
void Matrix::add(Matrix b)
{
  if((b.row == row) && (b.col == col))
  {
    for (int i=0; i<row; i++)
    {
      for (int j=0;j<col;j++)
      {
        std::cout << matrix[i][j] + b.matrix[i][j] << " ";
      }
    std::cout<<std::endl;
    }
  }
  else
  {
    std::cout << "Error: Matrix elements don't match" << std::endl;
  }
}
 
void Matrix::multiply(Matrix b)
{
  if(col == b.row)
  {
    int sum = 0;
    for (int i=0; i<row; i++)
    {
      for (int j=0;j<b.col;j++)
      {
        for (int k=0; k<b.row; k++)
        {
          sum += matrix[i][k] * b.matrix[k][j];
        }
      std::cout << sum << " ";
      sum = 0;
      }
      std::cout << std::endl;
    }
  }
  else
  {
    std::cout << "Error: Matrix elements don't match" << std::endl;
  }
}
 
 
 
int main() {
  Matrix mat1(2,2);
  mat1.set_val(1, 1, 1);
  mat1.set_val(1, 2, 2);
  mat1.set_val(2, 1, 3);
  mat1.set_val(2, 2, 4);
  Matrix mat2(2,1);
  mat2.set_val(1, 1, 1);
  mat2.set_val(2, 1, 2);
  mat1.add(mat2);
  mat1.multiply(mat2);
}