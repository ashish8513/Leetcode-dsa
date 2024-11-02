// There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

// For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
// When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

// You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

// Return the chair number that the friend numbered targetFriend will sit on.


const smallestChair = function (times, targetFriend) {
    const chairs = [];
    const ARRIVE = "arrive";
    const LEAVE = "leave";

    const queue = times
        .reduce((arr, t, i) => {
            arr.push({ id: i, time: t[0], action: ARRIVE });
            arr.push({ id: i, time: t[1], action: LEAVE });
            return arr;
        }, [])
        .sort((a, b) => {
            if (a.time === b.time) {
                if (a.action === LEAVE) return -1;
                else return 1;
            }
            return a.time - b.time;
        });

    let friend;
    for (let i = 0; i < queue.length; i++) {
        friend = queue[i];
        if (friend.action === ARRIVE) {
            const index = findChair(chairs);
            chairs[index] = friend.id;
        } else {
            const index = chairs.indexOf(friend.id);
            chairs[index] = undefined;
        }
        if (friend.id === targetFriend) {
            break;
        }
    }

    return chairs.indexOf(friend.id);
};

function findChair(chairs) {
    if (!chairs.length) return 0;
    const nextIndex = chairs.indexOf(undefined);
    if (nextIndex < 0) {
        return chairs.length;
    } else {
        return nextIndex;
    }
}