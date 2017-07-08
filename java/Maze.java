/**
 * Created by Daniel on 7/1/17.
 */
public class Maze {

    int finishRow = 8;
    int finishCol = 9;

    char[][] maze = {
            {'0','0','0','0','0','0','0','0','0','0'},
            {'1','1','0','1','1','1','1','0','1','0'},
            {'0','1','0','1','0','0','1','0','1','0'},
            {'0','1','1','1','0','1','1','0','1','0'},
            {'0','1','0','1','0','1','0','0','1','0'},
            {'0','1','0','1','0','1','1','1','1','0'},
            {'0','1','0','0','0','0','0','1','0','0'},
            {'0','1','0','1','1','1','0','1','0','0'},
            {'0','1','1','1','0','1','0','1','1','1'},
            {'0','0','0','0','0','0','0','0','0','0'}
    };


    public boolean solve(int row, int col) {
        if(maze[row][col] == '0' || maze[row][col] == '#') return false;
        if( row == finishRow && col == finishCol ) return true;

        maze[row][col] = '#'; // mark as possible path

        if( solve(row-1, col) ) return true; // move up
        if( solve(row, col+1) ) return true; // move right
        if( solve(row+1, col) ) return true; // move down
        if( solve(row, col-1) ) return true; // move left

        maze[row][col] = '1'; // couldn't reach end through this block, mark it as empty

        return false;
    }

    public void printMaze() {
        for(int i = 0; i < maze.length; i++) {
            String str = "";
            for(int j=0; j < maze[i].length; j++) {
                str += maze[i][j];
            }
            System.out.println(str);
        }
    }

}
