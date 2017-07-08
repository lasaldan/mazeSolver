#include<stdio.h>
typedef enum { false, true } bool;

int maze[10][10] = {
  {0,0,0,0,0,0,0,0,0,0},
  {1,1,0,1,1,1,1,0,1,0},
  {0,1,0,1,0,0,1,0,1,0},
  {0,1,1,1,0,1,1,0,1,0},
  {0,1,0,1,0,1,0,0,1,0},
  {0,1,0,1,0,1,1,1,1,0},
  {0,1,0,0,0,0,0,1,0,0},
  {0,1,0,1,1,1,0,1,0,0},
  {0,1,1,1,0,1,0,1,1,1},
  {0,0,0,0,0,0,0,0,0,0}
};

int finishRow = 8;
int finishCol = 9;
int gridSize = 10;

bool solve(int row, int col) {

  if(maze[row][col] == 0 || maze[row][col] == 2)
    return false;

  if(row == finishRow && col == finishCol)
    return true;

  maze[row][col] = 2;

  if (solve(row-1, col))
    return true;

  if (solve(row, col+1))
    return true;

  if (solve(row+1, col))
    return true;

  if (solve(row, col-1))
    return true;

  maze[row][col] = 1;
  
  return false;
}

int main()
{
  int row = 1;
  int col = 0;

  solve(row, col);
  for(int i = 0; i < gridSize; i++){
    for(int j = 0; j < gridSize; j++)
      printf("%i",maze[i][j]);
    printf("\n");
  }

}
//
// int maze[10][10] = {
//   {0,0,0,0,0,0,0,0,0,0},
//   {1,1,0,1,1,1,1,0,1,0},
//   {0,1,0,1,0,0,1,0,1,0},
//   {0,1,1,1,0,1,1,0,1,0},
//   {0,1,0,1,0,1,0,0,1,0},
//   {0,1,0,1,0,1,1,1,1,0},
//   {0,1,0,0,0,0,0,1,0,0},
//   {0,1,0,1,1,1,0,1,0,0},
//   {0,1,1,1,0,1,0,1,1,1},
//   {0,0,0,0,0,0,0,0,0,0}
// };
//
//
// int finishRow = 8;
// int finishCol = 9;
// int gridSize = 10;
//
// bool solve(int row, int col) {
//   if(maze[row][col] == 0 || maze[row][col] == 2) return false;
//   if(row == finishRow && col == finishCol) return true;
//
//   maze[row][col] = 2;
//
//   if (solve(row-1, col)) return true;
//   if (solve(row, col+1)) return true;
//   if (solve(row+1, col)) return true;
//   if (solve(row, col-1)) return true;
//
//   maze[row][col] = 1;
//
//   return false;
//
// }
//
//
// int main()
// {
//   int row = 1;
//   int col = 0;
//
//   solve(row, col);
//
//   // for(int i = 0; i < gridSize; i++){
//   //   for(int j = 0; j < gridSize; j++)
//   //     std::cout << maze[i][j];
//   //   std::cout << std::endl;
//   // }
// }
