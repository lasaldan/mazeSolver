<?php
  $maze = [
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
  ];

  $row = 1;
  $col = 0;

  $finishRow = 8;
  $finishCol = 9;

  function solve($row, $col) {
    global $maze, $finishRow, $finishCol;

    //print_maze();

    if($maze[$row][$col] == 0 || $maze[$row][$col] == "#")
      return false;

    if($row == $finishRow && $col == $finishCol) {
      print("FOUND END");
      return true;
    }

    $maze[$row][$col] = "#";

    if (solve($row-1, $col))
      return true;

    if (solve($row, $col+1))
      return true;

    if (solve($row+1, $col))
      return true;

    if (solve($row, $col-1))
      return true;

    $maze[$row][$col] = 1;

    return false;

  }

  function print_maze() {
    global $maze;
    for($i = 0; $i < count($maze); $i ++) {
      $string = "";
      for($j = 0; $j < count($maze[$i]); $j ++)
        $string .= $maze[$i][$j];
      print($string."\n");
    }
  }

  solve($row, $col);
  print_maze()
?>
