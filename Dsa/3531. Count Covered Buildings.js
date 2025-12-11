// You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].

// A building is covered if there is at least one building in all four directions: left, right, above, and below.

// Return the number of covered buildings.


/**
 * @param {number} n
 * @param {number[][]} buildings
 * @return {number}
 */
function countCoveredBuildings(n, buildings) {
  const rowMin = new Map(); 
  const rowMax = new Map();
  const colMin = new Map(); 
  const colMax = new Map(); 

  for (const [x, y] of buildings) {
    if (!rowMin.has(x) || y < rowMin.get(x)) rowMin.set(x, y);
    if (!rowMax.has(x) || y > rowMax.get(x)) rowMax.set(x, y);
    if (!colMin.has(y) || x < colMin.get(y)) colMin.set(y, x);
    if (!colMax.has(y) || x > colMax.get(y)) colMax.set(y, x);
  }

  let covered = 0;
  for (const [x, y] of buildings) {

    const minY = rowMin.get(x), maxY = rowMax.get(x);
    const minX = colMin.get(y), maxX = colMax.get(y);

    if (minY < y && y < maxY && minX < x && x < maxX) {
      covered++;
    }
  }

  return covered;
}

const n = 5;
const buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]];
console.log(countCoveredBuildings(n, buildings)); 
