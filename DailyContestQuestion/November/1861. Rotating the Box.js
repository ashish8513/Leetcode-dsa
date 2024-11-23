// You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

// A stone '#'
// A stationary obstacle '*'
// Empty '.'
// The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

// It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

// Return an n x m matrix representing the box after the rotation described above.

var rotateTheBox = function (box) {
    let countStones = 0;
    for (let rowIndex = 0; rowIndex < box.length; rowIndex++) {
        countStones = 0;
        for (let columnIndex = 0; columnIndex < box[rowIndex].length; columnIndex++) {
            if (box[rowIndex][columnIndex] === '#') {
                box[rowIndex][columnIndex] = '.';
                countStones += 1;
            }
            if (box[rowIndex][columnIndex] === '*' && countStones > 0) {
                let tempColumnIndex = columnIndex - 1;
                while (countStones > 0) {
                    box[rowIndex][tempColumnIndex--] = '#';
                    countStones--;
                }
                countStones = 0;
            }
            if (columnIndex === box[rowIndex].length - 1 && countStones > 0) {
                let tempColumnIndex = columnIndex;
                while (countStones > 0) {
                    box[rowIndex][tempColumnIndex--] = '#';
                    countStones--;
                }
                countStones = 0;
            }
        }
    }
    const output = [];
    for (let columnIndex = 0; columnIndex < box[0].length; columnIndex++) {
        output[columnIndex] = [];
        for (let rowIndex = box.length - 1; rowIndex >= 0; rowIndex--) {
            output[columnIndex].push(box[rowIndex][columnIndex]);
        }
    }
    return output;
};