// Design your implementation of the circular double-ended queue (deque).

// Implement the MyCircularDeque class:

// MyCircularDeque(int k) Initializes the deque with a maximum size of k.
// boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
// int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
// int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
// boolean isEmpty() Returns true if the deque is empty, or false otherwise.
// boolean isFull() Returns true if the deque is full, or false otherwise.

class MyCircularDeque {
    constructor(k) {
        this.capacity = k;
        this.deque = new Array(k).fill(null); // Create an array of size k filled with null
        this.front = 0;
        this.rear = 0;
        this.size = 0;
    }

    // Insert an element at the front of the deque
    insertFront(value) {
        if (this.isFull()) return false;
        this.front = (this.front - 1 + this.capacity) % this.capacity; // Move front pointer backward
        this.deque[this.front] = value;
        this.size++;
        return true;
    }

    // Insert an element at the rear of the deque
    insertLast(value) {
        if (this.isFull()) return false;
        this.deque[this.rear] = value;
        this.rear = (this.rear + 1) % this.capacity; // Move rear pointer forward
        this.size++;
        return true;
    }

    // Delete the front element
    deleteFront() {
        if (this.isEmpty()) return false;
        this.deque[this.front] = null;
        this.front = (this.front + 1) % this.capacity; // Move front pointer forward
        this.size--;
        return true;
    }

    // Delete the rear element
    deleteLast() {
        if (this.isEmpty()) return false;
        this.rear = (this.rear - 1 + this.capacity) % this.capacity; // Move rear pointer backward
        this.deque[this.rear] = null;
        this.size--;
        return true;
    }

    // Get the front item
    getFront() {
        if (this.isEmpty()) return -1;
        return this.deque[this.front];
    }

    // Get the rear item
    getRear() {
        if (this.isEmpty()) return -1;
        return this.deque[(this.rear - 1 + this.capacity) % this.capacity]; // The last element is at rear - 1 position
    }

    // Check if the deque is empty
    isEmpty() {
        return this.size === 0;
    }

    // Check if the deque is full
    isFull() {
        return this.size === this.capacity;
    }
}
