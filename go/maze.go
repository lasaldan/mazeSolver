package main

import "fmt"


var maze = [10][10]int{
  {0,0,0,0,0,0,0,0,0,0},
  {1,1,0,1,1,1,1,0,1,0},
  {0,1,0,1,0,0,1,0,1,0},
  {0,1,1,1,0,1,1,0,1,0},
  {0,1,0,1,0,1,0,0,1,0},
  {0,1,0,1,0,1,1,1,1,0},
  {0,1,0,0,0,0,0,1,0,0},
  {0,1,0,1,1,1,0,1,0,0},
  {0,1,1,1,0,1,0,1,1,1},
  {0,0,0,0,0,0,0,0,0,0},
}

var finishRow = 8;
var finishCol = 9;
var gridSize = 10;

func solve(row int, col int) bool {

  if(maze[row][col] == 0 || maze[row][col] == 2) {
    return false;
  }

  if(row == finishRow && col == finishCol) {
    return true;
  }

  maze[row][col] = 2;

  if (solve(row-1, col)) {
    return true;
  }

  if (solve(row, col+1)) {
    return true;
  }

  if (solve(row+1, col)) {
    return true;
  }

  if (solve(row, col-1)) {
    return true;
  }

  maze[row][col] = 1;

  return false;
}

func main() {

  var row = 1;
  var col = 0;

  solve(row, col);

  for i := 0; i < gridSize; i++ {
    for j := 0; j < gridSize; j++ {
      fmt.Printf("%v",maze[i][j]);
    }
    fmt.Printf("\n")
  }
}
