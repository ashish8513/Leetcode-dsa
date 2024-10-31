// There are some robots and factories on the X-axis. You are given an integer array robot where robot[i] is the position of the ith robot. You are also given a 2D integer array factory where factory[j] = [positionj, limitj] indicates that positionj is the position of the jth factory and that the jth factory can repair at most limitj robots.

// The positions of each robot are unique. The positions of each factory are also unique. Note that a robot can be in the same position as a factory initially.

// All the robots are initially broken; they keep moving in one direction. The direction could be the negative or the positive direction of the X-axis. When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.

// At any moment, you can set the initial direction of moving for some robot. Your target is to minimize the total distance traveled by all the robots.

// Return the minimum total distance traveled by all the robots. The test cases are generated such that all the robots can be repaired.

// Note that

// All robots move at the same speed.
// If two robots move in the same direction, they will never collide.
// If two robots move in opposite directions and they meet at some point, they do not collide. They cross each other.
// If a robot passes by a factory that reached its limits, it crosses it as if it does not exist.
// If the robot moved from a position x to a position y, the distance it moved is |y - x|.



/**
 * @param {number[]} robot
 * @param {number[][]} factory
 * @return {number}
 */
var minimumTotalDistance = function(robot, factory) {
     robot.sort((a, b) => a - b);
    factory.sort((a, b) => a[0] - b[0]);

    const memo = new Map();

    function helper(currRobot, currFact, usedCapacity) {
        if (currRobot === robot.length) return 0;
        if (currFact === factory.length) return Number.MAX_SAFE_INTEGER;

        const key = `${currRobot},${currFact},${usedCapacity}`;
        if (memo.has(key)) return memo.get(key);

        let minDist = Number.MAX_SAFE_INTEGER;

        // Option 1: Skip to next factory
        minDist = helper(currRobot, currFact + 1, 0);

        // Option 2: Use current factory if capacity allows
        const [position, capacity] = factory[currFact];
        if (usedCapacity < capacity) {
            const dist = Math.abs(robot[currRobot] - position);
            minDist = Math.min(
                minDist,
                dist + helper(currRobot + 1, currFact, usedCapacity + 1)
            );
        }

        memo.set(key, minDist);
        return minDist;
    }

    return helper(0, 0, 0);
};