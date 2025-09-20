// Design a data structure that can efficiently manage data packets in a network router. Each data packet consists of the following attributes:

// source: A unique identifier for the machine that generated the packet.
// destination: A unique identifier for the target machine.
// timestamp: The time at which the packet arrived at the router.
// Implement the Router class:

// Router(int memoryLimit): Initializes the Router object with a fixed memory limit.

// memoryLimit is the maximum number of packets the router can store at any given time.
// If adding a new packet would exceed this limit, the oldest packet must be removed to free up space.
// bool addPacket(int source, int destination, int timestamp): Adds a packet with the given attributes to the router.

// A packet is considered a duplicate if another packet with the same source, destination, and timestamp already exists in the router.
// Return true if the packet is successfully added (i.e., it is not a duplicate); otherwise return false.
// int[] forwardPacket(): Forwards the next packet in FIFO (First In First Out) order.

// Remove the packet from storage.
// Return the packet as an array [source, destination, timestamp].
// If there are no packets to forward, return an empty array.
// int getCount(int destination, int startTime, int endTime):

// Returns the number of packets currently stored in the router (i.e., not yet forwarded) that have the specified destination and have timestamps in the inclusive range [startTime, endTime].
// Note that queries for addPacket will be made in increasing order of timestamp

/**
 * @param {number} memoryLimit
 */
var Router = function(memoryLimit) {
    this.capacity = memoryLimit;
    this.size = 0;

    // FIFO storage of packets
    this.deque = new CircularDeque(memoryLimit);

    // For O(1) duplicate detection
    this.seen = new Set();

    // destination => { ts: number[], head: number }
    this.destinationMap = new Map();
};

Router.prototype.addPacket = function(source, destination, timestamp) {
    // 1) Duplicate check
    const key = source + '|' + destination + '|' + timestamp;
    if (this.seen.has(key)) return false;

    // 2) we evict oldest if at capacity
    if (this.size === this.capacity) {
        const ev = this.deque.removeFront();
        this.size--;
        const evKey = ev.source + '|' + ev.destination + '|' + ev.timestamp;
        this.seen.delete(evKey);

        // we advance head in that destination’s timestamp queue
        const entryEv = this.destinationMap.get(ev.destination);
        if (entryEv && entryEv.ts[entryEv.head] === ev.timestamp) {
            entryEv.head++;
        }
    }

    // 3) we add new packet
    this.deque.addBack({ source, destination, timestamp });
    this.size++;
    this.seen.add(key);

    // 4) we record its timestamp
    let entry = this.destinationMap.get(destination);
    if (!entry) {
        entry = { ts: [], head: 0 };
        this.destinationMap.set(destination, entry);
    }
    entry.ts.push(timestamp);

    return true;
};

Router.prototype.forwardPacket = function() {
    if (this.size === 0) return [];
    const packet = this.deque.removeFront();
    this.size--;

    // we remove from duplicate-set
    const key = packet.source + '|' + packet.destination + '|' + packet.timestamp;
    this.seen.delete(key);

    // we advance that destination’s head pointer
    const entry = this.destinationMap.get(packet.destination);
    if (entry && entry.ts[entry.head] === packet.timestamp) {
        entry.head++;
    }

    return [packet.source, packet.destination, packet.timestamp];
};

Router.prototype.getCount = function(destination, startTime, endTime) {
    const entry = this.destinationMap.get(destination);
    if (!entry) return 0;

    const arr = entry.ts, start = entry.head, n = arr.length;
    if (start >= n) return 0;

    // lowerBound in [start, n)
    let l = start, r = n;
    while (l < r) {
        const m = (l + r) >> 1;
        if (arr[m] < startTime) l = m + 1;
        else r = m;
    }
    const lower = l;

    // upperBound in [start, n)
    l = start; r = n;
    while (l < r) {
        const m = (l + r) >> 1;
        if (arr[m] <= endTime) l = m + 1;
        else r = m;
    }
    const upper = l;

    return upper - lower;
};

/**
 * A circular-buffer deque supporting O(1) add/remove at both ends.
 */
class CircularDeque {
    constructor(capacity) {
        this.capacity = capacity + 1;
        this.buffer = new Array(this.capacity);
        this.front = 0;
        this.rear = 0;
    }

    isEmpty() {
        return this.front === this.rear;
    }

    isFull() {
        return (this.rear + 1) % this.capacity === this.front;
    }

    addBack(value) {
        if (this.isFull()) throw new Error("Deque is full");
        this.buffer[this.rear] = value;
        this.rear = (this.rear + 1) % this.capacity;
    }

    removeFront() {
        if (this.isEmpty()) throw new Error("Deque is empty");
        const v = this.buffer[this.front];
        this.front = (this.front + 1) % this.capacity;
        return v;
    }

    // for duplicate detection
    containsPacket(src, dst, ts) {
        for (let i = this.front; i !== this.rear; i = (i + 1) % this.capacity) {
            const p = this.buffer[i];
            if (p.source === src && p.destination === dst && p.timestamp === ts) {
                return true;
            }
        }
        return false;
    }
}

/** 
 * Your Router object will be instantiated and called as such:
 * var obj = new Router(memoryLimit)
 * var b1 = obj.addPacket(source, destination, timestamp)
 * var p1 = obj.forwardPacket()
 * var c1 = obj.getCount(destination, startTime, endTime)
 */  