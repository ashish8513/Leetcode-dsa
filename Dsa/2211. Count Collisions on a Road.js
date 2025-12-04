// There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 from left to right and each car is present at a unique point.

// You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' denoting whether the ith car is moving towards the left, towards the right, or staying at its current point respectively. Each moving car has the same speed.

// The number of collisions can be calculated as follows:

// When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
// When a moving car collides with a stationary car, the number of collisions increases by 1.
// After a collision, the cars involved can no longer move and will stay at the point where they collided. Other than that, cars cannot change their state or direction of motion.

// Return the total number of collisions that will happen on the road.

/**
 * @param {string} directions
 * @return {number}
 */
const countCollisions = directions => {
  let start, end, counter = 0, n = directions.length;

  for (let i = 0; i < n; i++)
    if (directions[i] !== `L`) {
      start = i;
      break;
    }

  for (let i = n - 1; i > -1; i--)
    if (directions[i] !== `R`) {
      end = i;
      break;
    }

  for (let i = start; i < end + 1; i++) 
    if (directions[i] !== `S`)
      counter++;

  return counter;
}
