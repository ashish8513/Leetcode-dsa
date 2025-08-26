// You are given a 2D 0-indexed integer array dimensions.

// For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.

// Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.



/**
 * @param {number[][]} dimensions
 * @return {number}
 */
var areaOfMaxDiagonal = function(dimensions) {
    let maxDiagonal = -1;
    let maxArea = -1;

    for (let [l, w] of dimensions) {
        let diagonal = Math.sqrt(l * l + w * w);
        let area = l * w;

        if (diagonal > maxDiagonal) {
            maxDiagonal = diagonal;
            maxArea = area;
        } else if (diagonal === maxDiagonal) {
            maxArea = Math.max(maxArea, area);
        }
    }

    return maxArea;
};