@maze = [
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

@finishRow = 8
@finishCol = 9

def solve(row, col)

  if @maze[row][col] == 0 || @maze[row][col] == 2
    return false
  end

  if row == @finishRow && col == @finishCol
    return true
  end

  @maze[row][col] = 2

  if solve(row-1, col)
    return true
  end

  if solve(row, col+1)
    return true
  end

  if solve(row+1, col)
    return true
  end

  if solve(row, col-1)
    return true
  end

  @maze[row][col] = 1

  return false
end

def print_maze
  @maze.each do |row|
    puts row.join("")
  end
end

solve(row, col)
print_maze
