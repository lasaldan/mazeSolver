/**
 * Created by Daniel on 7/1/17.
 */
import java.lang.System;

public class Main {
    public static void main(String[] args) {
        Maze maze = new Maze();
        maze.solve(1,0);
        maze.printMaze();
    }
}