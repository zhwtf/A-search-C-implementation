#### README
### A* Search PathFinding -- C++ Implementation 

### Introduction of A* Search
#### In the assignment, we need to find a path from the start cell to the goal cell. Use the heuristic function to calculate the most efficient path. I use the Manhattan method, where you calculate the total number of squares moved horizontally and vertically to reach the target square from the current square, ignoring diagonal movement, and ignoring any obstacles that may be in the way. 

#### Manhatten method: H(n) = abs(start cell's x coordinate - goal cell's x coordinate) + abs(start cell's y coordinate - goal cell's y coordinate) This means that the cell can only expand in the vertical line and horizontal line. 
*       # 
*    #  A  # 
*       #      A is the cell that I want to expand and '#' is the only way that it can expand .




### How to run the program
* So just open it with xcode(if use Mac) and run the program
* Or open the executable file in Terminal 

* After the program started, input the start point and goal point(range from 0 to 17). If the points hit the block point(or out of range), you will be asked to re-enter the points again.

* Be careful, the input should be, for example, 0 0, use whitespace between the x and y coordinate. Not(0,0) 

* Then you will get the output.
