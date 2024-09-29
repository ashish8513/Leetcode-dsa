// 432. All O`one Data Structure
// Solved
// Hard
// Topics
// Companies
// Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

// Implement the AllOne class:

// AllOne() Initializes the object of the data structure.
// inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
// dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
// getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
// getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
// Note that each function must run in O(1) average time complexity.

class ListNode {
    constructor(count) {
        this.count = count;
        this.keys = new Set();
        this.prev = null;
        this.next = null;
    }
}

class AllOne {
    constructor() {
        this.keyCount = new Map(); // Stores count for each key
        this.countNodeMap = new Map(); // Maps count to its ListNode in the doubly linked list
        this.head = new ListNode(0); // Dummy head (smallest count)
        this.tail = new ListNode(Infinity); // Dummy tail (largest count)
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    // Helper function to insert a new node after a given node
    _insertNodeAfter(newNode, prevNode) {
        let nextNode = prevNode.next;
        prevNode.next = newNode;
        newNode.prev = prevNode;
        newNode.next = nextNode;
        nextNode.prev = newNode;
    }

    // Helper function to remove a node
    _removeNode(node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        this.countNodeMap.delete(node.count);
    }

    // Increment the count of the key
    inc(key) {
        let count = this.keyCount.get(key) || 0;
        this.keyCount.set(key, count + 1);

        let currentNode = this.countNodeMap.get(count);
        let newNode;

        if (!this.countNodeMap.has(count + 1)) {
            newNode = new ListNode(count + 1);
            this.countNodeMap.set(count + 1, newNode);
            if (!currentNode) {
                this._insertNodeAfter(newNode, this.head); // For new keys with count 1
            } else {
                this._insertNodeAfter(newNode, currentNode);
            }
        } else {
            newNode = this.countNodeMap.get(count + 1);
        }

        newNode.keys.add(key);

        if (currentNode) {
            currentNode.keys.delete(key);
            if (currentNode.keys.size === 0) {
                this._removeNode(currentNode);
            }
        }
    }

    // Decrement the count of the key
    dec(key) {
        let count = this.keyCount.get(key);
        if (!count) return;

        let currentNode = this.countNodeMap.get(count);
        currentNode.keys.delete(key);

        if (count === 1) {
            this.keyCount.delete(key);
        } else {
            this.keyCount.set(key, count - 1);
            if (!this.countNodeMap.has(count - 1)) {
                let newNode = new ListNode(count - 1);
                this.countNodeMap.set(count - 1, newNode);
                this._insertNodeAfter(newNode, currentNode.prev);
            }
            this.countNodeMap.get(count - 1).keys.add(key);
        }

        if (currentNode.keys.size === 0) {
            this._removeNode(currentNode);
        }
    }

    // Get a key with the maximum count
    getMaxKey() {
        if (this.tail.prev === this.head) return "";
        return [...this.tail.prev.keys][0];
    }

    // Get a key with the minimum count
    getMinKey() {
        if (this.head.next === this.tail) return "";
        return [...this.head.next.keys][0];
    }
}
