maze = [
  [0,0,0,0,0,0,0,0,0,0],
  [1,1,0,1,1,1,1,0,1,0],
  [0,1,0,1,0,0,1,0,1,0],
  [0,1,1,1,0,1,1,0,1,0],
  [0,1,0,1,0,1,0,0,1,0],
  [0,1,0,1,0,1,1,1,1,0],
  [0,1,0,0,0,0,0,1,0,0],
  [0,1,0,1,1,1,0,1,0,0],
  [0,1,1,1,0,1,0,1,1,1],
  [0,0,0,0,0,0,0,0,0,0]
]

var row = 1
var col = 0

var finishRow = 8
var finishCol = 9

function solve(row, col){

  if(!maze[row][col]) return false
  if(row == finishRow && col == finishCol) return true

  maze[row][col] == "#"

  if (solve(row-1, col)) return true
  if (solve(row, col+1)) return true
  if (solve(row+1, col)) return true
  if (solve(row, col-1)) return true

  maze[row][col] == "0"

  return false

}

solve(row, col)
console.log(maze)
