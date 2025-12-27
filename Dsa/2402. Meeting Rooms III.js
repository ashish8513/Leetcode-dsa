// You are given an integer n. There are n rooms numbered from 0 to n - 1.

// You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

// Meetings are allocated to rooms in the following manner:

// Each meeting will take place in the unused room with the lowest number.
// If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
// When a room becomes unused, meetings that have an earlier original start time should be given the room.
// Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

// A half-closed interval [a, b) is the interval between a and b including a and not including b.

import heapq

class Solution:
    def mostBooked(self, n: int, meetings: list[list[int]]) -> int:
        # Sort meetings by start time
        meetings.sort()

        # Min-heap of available rooms
        availableRooms = list(range(n))
        heapq.heapify(availableRooms)

        # Min-heap of busy rooms: (endTime, roomNumber)
        busyRooms = []

        # Count meetings per room
        count = [0] * n

        for start, end in meetings:
            duration = end - start

            # Free rooms which are done before current meeting starts
            while busyRooms and busyRooms[0][0] <= start:
                _, room = heapq.heappop(busyRooms)
                heapq.heappush(availableRooms, room)

            # If room is available
            if availableRooms:
                room = heapq.heappop(availableRooms)
                heapq.heappush(busyRooms, (end, room))
            else:
                # Delay meeting
                endTime, room = heapq.heappop(busyRooms)
                heapq.heappush(busyRooms, (endTime + duration, room))

            count[room] += 1

        # Return room with max meetings (smallest index if tie)
        maxMeetings = max(count)
        for i in range(n):
            if count[i] == maxMeetings:
                return i
