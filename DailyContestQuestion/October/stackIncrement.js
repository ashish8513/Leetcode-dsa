// Design a stack that supports increment operations on its elements.

// Implement the CustomStack class:

// CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
// void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
// int pop() Pops and returns the top of the stack or -1 if the stack is empty.
// void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.

class CustomStack {
    constructor(maxSize) {
        this.maxSize = maxSize; // Maximum size of the stack
        this.stack = []; // Stack to hold the elements
        this.increment = Array(maxSize).fill(0); // Array to hold increment values
    }

    push(x) {
        // Add x to the stack if it hasn't reached the maximum size
        if (this.stack.length < this.maxSize) {
            this.stack.push(x);
        }
    }

    pop() {
        // Pop the top element of the stack
        if (this.stack.length === 0) {
            return -1; // Return -1 if the stack is empty
        }

        const index = this.stack.length - 1; // Get the index of the top element
        const value = this.stack.pop(); // Pop the element from the stack

        // Apply the increment to the popped value if it exists
        if (index > 0) {
            this.increment[index - 1] += this.increment[index]; // Carry over the increment to the next element
        }

        // Get the increment value for the popped element and reset it
        const incrementValue = this.increment[index];
        this.increment[index] = 0; // Reset the increment for the popped element
        return value + incrementValue; // Return the value with its increment
    }

    inc(k, val) {
        // Increment the bottom k elements by val
        const limit = Math.min(k, this.stack.length); // Get the minimum of k and the stack length
        if (limit > 0) {
            this.increment[limit - 1] += val; // Increment the increment value for the k-th element
        }
    }
}

// Example usage:
const customStack = new CustomStack(3);
customStack.push(1);
customStack.push(2);
console.log(customStack.pop()); // Output: 2
customStack.push(3);
customStack.push(4); // Stack is full, 4 won't be added
customStack.inc(2, 5); // Increment the bottom 2 elements by 5
console.log(customStack.pop()); // Output: 8 (3 + 5)
console.log(customStack.pop()); // Output: 6 (1 + 5)
console.log(customStack.pop()); // Output: -1 (stack is empty)
