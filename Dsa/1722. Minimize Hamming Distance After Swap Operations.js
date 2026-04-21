// You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

// The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

// Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.


var minimumHammingDistance = function(source, target, allowedSwaps) {
    const size = source.length;
    const union = [];
    const sourceMap = new Map();
    const find = (node) => union[node] === node ? node : find(union[node]);
    let result = 0;

    for (let index = 0; index < size; index++) union[index] = index;
    for (const [a, b] of allowedSwaps) {
        const parentA = find(a);
        const parentB = find(b);
        
        if (parentA == parentB) continue;
        union[parentA] = parentB; 
    }
    for (let index = 0; index < size; index++) {
        const parent = find(index);
        const group = sourceMap.get(parent);
        const current = source[index];

        group 
            ? group.set(current, (group.get(current) ?? 0) + 1)
            : sourceMap.set(parent, new Map([[current, 1]]));
    }
    for (let index = 0; index < size; index++) {
        const group = sourceMap.get(find(index));
        const count = group.get(target[index]);

        count ? group.set(target[index], count - 1) : result += 1;
    }
    return result;
};
