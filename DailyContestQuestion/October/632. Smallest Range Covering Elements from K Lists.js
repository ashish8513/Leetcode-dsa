// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

/**
 * @param {number[][]} nums
 * @return {number[]}
 */
class MinHeap {
    constructor() {
        this.heap = [];
    }

    // Add an element to the heap
    push(val) {
        this.heap.push(val);
        this.bubbleUp(this.heap.length - 1);
    }

    // Get and remove the smallest element from the heap
    pop() {
        const min = this.heap[0];
        const end = this.heap.pop();
        if (this.heap.length > 0) {
            this.heap[0] = end;
            this.bubbleDown(0);
        }
        return min;
    }

    // Maintain the heap structure after adding an element
    bubbleUp(idx) {
        const element = this.heap[idx];
        while (idx > 0) {
            let parentIdx = Math.floor((idx - 1) / 2);
            let parent = this.heap[parentIdx];
            if (element[0] >= parent[0]) break;
            this.heap[idx] = parent;
            idx = parentIdx;
        }
        this.heap[idx] = element;
    }

    // Maintain the heap structure after removing the smallest element
    bubbleDown(idx) {
        const length = this.heap.length;
        const element = this.heap[idx];
        while (true) {
            let leftChildIdx = 2 * idx + 1;
            let rightChildIdx = 2 * idx + 2;
            let swap = null;

            if (leftChildIdx < length) {
                let leftChild = this.heap[leftChildIdx];
                if (leftChild[0] < element[0]) {
                    swap = leftChildIdx;
                }
            }

            if (rightChildIdx < length) {
                let rightChild = this.heap[rightChildIdx];
                if ((swap === null && rightChild[0] < element[0]) || 
                    (swap !== null && rightChild[0] < this.heap[swap][0])) {
                    swap = rightChildIdx;
                }
            }

            if (swap === null) break;
            this.heap[idx] = this.heap[swap];
            idx = swap;
        }
        this.heap[idx] = element;
    }
}

function smallestRange(lists) {
    const minHeap = new MinHeap();
    let max = -Infinity;
    let rangeStart = 0, rangeEnd = Infinity;

    // Initialize the heap with the first element from each list
    for (let i = 0; i < lists.length; i++) {
        minHeap.push([lists[i][0], i, 0]);
        max = Math.max(max, lists[i][0]);
    }

    // Process until one of the lists is exhausted
    while (true) {
        let [minValue, listIdx, elementIdx] = minHeap.pop();

        // Update the range if it's smaller than the current best range
        if (max - minValue < rangeEnd - rangeStart || 
            (max - minValue === rangeEnd - rangeStart && minValue < rangeStart)) {
            rangeStart = minValue;
            rangeEnd = max;
        }

        // If we reach the end of one list, break the loop
        if (elementIdx + 1 >= lists[listIdx].length) break;

        // Add the next element from the same list to the heap
        let nextValue = lists[listIdx][elementIdx + 1];
        minHeap.push([nextValue, listIdx, elementIdx + 1]);
        max = Math.max(max, nextValue);
    }

    return [rangeStart, rangeEnd];
}

// Example usage:
let lists = [
    [4, 10, 15, 24, 26],
    [0, 9, 12, 20],
    [5, 18, 22, 30]
];

console.log(smallestRange(lists)); // Output: [20, 24]
