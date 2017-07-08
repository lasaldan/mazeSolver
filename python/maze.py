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

row = 1
col = 0

finishRow = 8
finishCol = 9

def solve(row, col):

    if maze[row][col] == 0 or maze[row][col] == 2:
        return False

    if row == finishRow and col == finishCol:
        return True

    maze[row][col] = 2

    if solve(row-1, col):
        return True

    if solve(row, col+1):
        return True

    if solve(row+1, col):
        return True

    if solve(row, col-1):
        return True

    maze[row][col] = 1

    return False

solve(row, col)
print maze
