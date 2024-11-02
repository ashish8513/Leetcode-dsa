// You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

// A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

// The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

// Implement the MyCalendarTwo class:

// MyCalendarTwo() Initializes the calendar object.
// boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar
var MyCalendarTwo = function () {
    this.events = [];
    this.overlaps = [];
};

/**
 * @param {number} start
 * @param {number} end
 * @return {boolean}
 */
MyCalendarTwo.prototype.book = function (start, end) {
    for (let [s, e] of this.overlaps) {
        if (Math.max(start, s) < Math.min(end, e)) {
            return false;
        }
    }

    for (let [s, e] of this.events) {
        if (Math.max(start, s) < Math.min(end, e)) {
            this.overlaps.push([Math.max(start, s), Math.min(end, e)]);
        }
    }

    this.events.push([start, end]);
    return true;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * var obj = new MyCalendarTwo()
 * var param_1 = obj.book(start,end)
 */