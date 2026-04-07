// A width x height grid is on an XY-plane with the bottom-left cell at (0, 0) and the top-right cell at (width - 1, height - 1). The grid is aligned with the four cardinal directions ("North", "East", "South", and "West"). A robot is initially at cell (0, 0) facing direction "East".

// The robot can be instructed to move for a specific number of steps. For each step, it does the following.

// Attempts to move forward one cell in the direction it is facing.
// If the cell the robot is moving to is out of bounds, the robot instead turns 90 degrees counterclockwise and retries the step.
// After the robot finishes moving the number of steps required, it stops and awaits the next instruction.

// Implement the Robot class:

// Robot(int width, int height) Initializes the width x height grid with the robot at (0, 0) facing "East".
// void step(int num) Instructs the robot to move forward num steps.
// int[] getPos() Returns the current cell the robot is at, as an array of length 2, [x, y].
// String getDir() Returns the current direction of the robot, "North", "East", "South", or "West".

class Robot {
private:
    int x = 0, y = 0;
    int w, h;
    int dir;
    // CCW order: East(0), North(1), West(2), South(3)
    int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int peri;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        dir = 0; // Initially East
        peri = 2 * (width + height) - 4;
    }
    
    void step(int num) {
        num %= peri;
        
        // Edge case: if we move a full lap back to the start, 
        // the robot faces South according to the problem rules.
        if (num == 0 && x == 0 && y == 0) {
            dir = 3; 
        }

        while (num > 0) {
            int nx = x + mov[dir][0];
            int ny = y + mov[dir][1];

            if (nx >= w || nx < 0 || ny >= h || ny < 0) {
                dir = (dir + 1) % 4; // Turn 90 degrees CCW
            } else {
                x = nx;
                y = ny;
                num--;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        string dirs[] = {"East", "North", "West", "South"};
        return dirs[dir];
    }
};
