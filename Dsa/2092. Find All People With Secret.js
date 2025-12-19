// You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

// Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

// The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

// Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.


/**
 * @param {number} n
 * @param {number[][]} meetings
 * @param {number} firstPerson
 * @return {number[]}
 */
var findAllPeople = function (n, meetings, firstPerson) {
  // People who currently know the secret
  const know = new Set([0, firstPerson]);

  // Sort meetings by time
  meetings.sort((a, b) => a[2] - b[2]);

  let i = 0;

  while (i < meetings.length) {
    let time = meetings[i][2];

    // Graph for current time
    const graph = new Map();
    const people = new Set();

    // Collect all meetings at same time
    while (i < meetings.length && meetings[i][2] === time) {
      const [x, y] = meetings[i];
      people.add(x);
      people.add(y);

      if (!graph.has(x)) graph.set(x, []);
      if (!graph.has(y)) graph.set(y, []);

      graph.get(x).push(y);
      graph.get(y).push(x);

      i++;
    }

    // BFS only from people who already know the secret
    const queue = [];
    const visited = new Set();

    for (let p of people) {
      if (know.has(p)) {
        queue.push(p);
        visited.add(p);
      }
    }

    while (queue.length) {
      const curr = queue.shift();
      know.add(curr);

      for (let nei of graph.get(curr) || []) {
        if (!visited.has(nei)) {
          visited.add(nei);
          queue.push(nei);
        }
      }
    }
  }

  return Array.from(know);
};
