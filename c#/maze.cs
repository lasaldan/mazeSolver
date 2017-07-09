public class MazeSolver
{

  public int[,] maze = new int[,] {
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

  public bool solve(int row, int col) {
    if(maze[row,col] == 0 || maze[row,col] == 2)
      return false;

    if(row == finishRow && col == finishCol)
      return true;

    maze[row,col] = 2;

    if (solve(row-1, col)) return true;
    if (solve(row, col+1)) return true;
    if (solve(row+1, col)) return true;
    if (solve(row, col-1)) return true;

    maze[row,col] = 1;

    return false;
  }

  public static void Main()
  {
    int row = 1;
    int col = 0;

    MazeSolver maze = new MazeSolver();
    maze.solve(row, col);

    for(int i = 0; i < maze.maze.GetLength(0); i++){
      for(int j = 0; j < maze.maze.GetLength(1); j++)
        System.Console.Write(maze.maze[i,j]);
      System.Console.WriteLine("");
    }
  }
}
