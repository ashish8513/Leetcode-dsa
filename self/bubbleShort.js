
function bubbleSort(arr) {
    let n = arr.length;
    let swapped;

    // Traverse through all array elements
    for (let i = 0; i < n - 1; i++) {
        swapped = false;

        // Last i elements are already in place
        for (let j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if elements are in the wrong order
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
                swapped = true;
            }
        }

        // If no two elements were swapped by the inner loop, break
        if (!swapped) break;
    }

    return arr;
}

// Example usage:
const array = [64, 34, 25, 12, 22, 11, 90];
console.log('Unsorted array:', array);
const sortedArray = bubbleSort(array);
console.log('Sorted array:', sortedArray);
