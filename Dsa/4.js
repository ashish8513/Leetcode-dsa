// You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.

// A V-shaped diagonal segment is defined as:

// The segment starts with 1.
// The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
// The segment:
// Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
// Continues the sequence in the same diagonal direction.
// Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.




/**
 * @param {number[][]} grid
 * @return {number}
 */
var lenOfVDiagonal = function (grid) {
    function Coord(i, j) {
        this.i = i;
        this.j = j;
    }

    Coord.prototype.add = function (delta) {
        return new Coord(this.i + delta.i, this.j + delta.j);
    };

    Coord.prototype.invert = function () {
        return new Coord(-this.i, -this.j);
    };

    Coord.prototype.checkBounds = function (max) {
        return this.i >= 0 &&
            this.j >= 0 &&
            this.i < max.i &&
            this.j < max.j;
    };

    Coord.prototype.getValue = function (matrix) {
        return matrix[this.i][this.j];
    };

    Coord.directions = [
        new Coord(-1, -1), // top-left
        new Coord(-1, 1),  // top-right
        new Coord(1, 1),   // bottom-right
        new Coord(1, -1),  // bottom-left
    ];

    function matrixMax(matrix, mapFn) {
        const n = matrix.length;
        const m = matrix[0].length;
        let max = -Infinity;
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                const result = mapFn(matrix[i][j], new Coord(i, j));
                max = Math.max(max, result);
            }
        }
        return max;
    }

    const NO_TURN = 0;
    const TURN = 1;
    const TURN_OPTIONS = 2;

    const DIRECTION_OPTIONS = Coord.directions.length;

    const START_VALUE = 1;

    const expectedValueMap = [
        2, // 2 after 0
        2, // 2 after 1
        0, // 0 after 2
    ];

    function clockwiseTurn(directionIndex) {
        return (directionIndex + 1) % DIRECTION_OPTIONS;
    }

    const bounds = new Coord(grid.length, grid[0].length);

    function memo(fn) {
        const cache = new Array(bounds.i * bounds.j * TURN_OPTIONS * DIRECTION_OPTIONS);
        return function (c, turn, directionIndex) {
            const hash = (c.i * bounds.j + c.j) * TURN_OPTIONS * DIRECTION_OPTIONS +
                turn * DIRECTION_OPTIONS +
                directionIndex;
            const value = cache[hash];
            if (value !== undefined) {
                return value;
            }
            const result = fn(c, turn, directionIndex);
            cache[hash] = result;
            return result;
        };
    }

    const dp = memo(function (coord, turn, directionIndex) {
        const direction = Coord.directions[directionIndex];
        const prevCoord = coord.add(direction.invert());
        const prevValue = prevCoord.getValue(grid);
        const expectedValue = expectedValueMap[prevValue];
        const value = coord.getValue(grid);
        if (value !== expectedValue) {
            return 0;
        }
        const nextCoord = coord.add(direction);
        const nextResult = nextCoord.checkBounds(bounds) ?
            1 + dp(nextCoord, turn, directionIndex) :
            1;
        let turnResult = 1;
        if (turn) {
            const turnDirectionIndex = clockwiseTurn(directionIndex);
            const turnCoord = coord.add(Coord.directions[turnDirectionIndex]);
            if (turnCoord.checkBounds(bounds)) {
                turnResult = 1 + dp(turnCoord, NO_TURN, turnDirectionIndex);
            }
        }
        return Math.max(nextResult, turnResult);
    });

    return matrixMax(grid, function (value, coord) {
        if (value !== START_VALUE) {
            return 0;
        }
        return 1 + Math.max.apply(
            Math,
            Coord.directions.map(function (direction, i) {
                const nextCoord = coord.add(direction);
                if (nextCoord.checkBounds(bounds)) {
                    return dp(nextCoord, TURN, i);
                }
                return 0;
            })
        );
    });
};