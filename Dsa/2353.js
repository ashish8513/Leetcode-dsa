// Design a food rating system that can do the following:

// Modify the rating of a food item listed in the system.
// Return the highest-rated food item for a type of cuisine in the system.
// Implement the FoodRatings class:

// FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. The food items are described by foods, cuisines and ratings, all of which have a length of n.
// foods[i] is the name of the ith food,
// cuisines[i] is the type of cuisine of the ith food, and
// ratings[i] is the initial rating of the ith food.
// void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
// String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. If there is a tie, return the item with the lexicographically smaller name.
// Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

 

// Example 1:

// Input
// ["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
// [[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
// Output
// [null, "kimchi", "ramen", null, "sushi", null, "ramen"]

// Explanation
// FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
// foodRatings.highestRated("korean"); // return "kimchi"
//                                     // "kimchi" is the highest rated korean food with a rating of 9.
// foodRatings.highestRated("japanese"); // return "ramen"
//                                       // "ramen" is the highest rated japanese food with a rating of 14.
// foodRatings.changeRating("sushi", 16); // "sushi" now has a rating of 16.
// foodRatings.highestRated("japanese"); // return "sushi"
//                                       // "sushi" is the highest rated japanese food with a rating of 16.
// foodRatings.changeRating("ramen", 16); // "ramen" now has a rating of 16.
// foodRatings.highestRated("japanese"); // return "ramen"
//                                       // Both "sushi" and "ramen" have a rating of 16.
//                                       // However, "ramen" is lexicographically smaller than "sushi".
 

// Constraints:

// 1 <= n <= 2 * 104
// n == foods.length == cuisines.length == ratings.length
// 1 <= foods[i].length, cuisines[i].length <= 10
// foods[i], cuisines[i] consist of lowercase English letters.
// 1 <= ratings[i] <= 108
// All the strings in foods are distinct.
// food will be the name of a food item in the system across all calls to changeRating.
// cuisine will be a type of cuisine of at least one food item in the system across all calls to highestRated.
// At most 2 * 104 calls in total will be made to changeRating and highestRated


/**
 * @param {string[]} foods
 * @param {string[]} cuisines
 * @param {number[]} ratings
 */
var FoodRatings = function(foods, cuisines, ratings) {
    this.foodToCuisine = new Map();
    this.foodRatings = new Map();
    this.cuisineToFoods = new Map(); // cuisine -> heap

    for (let i = 0; i < foods.length; i++) {
        const food = foods[i];
        const cuisine = cuisines[i];
        const rating = ratings[i];

        this.foodToCuisine.set(food, cuisine);
        this.foodRatings.set(food, rating);

        if (!this.cuisineToFoods.has(cuisine)) {
            this.cuisineToFoods.set(cuisine, new MaxxHeap());
        }
        this.cuisineToFoods.get(cuisine).push([rating, food]);
    }
};

/** 
 * @param {string} food 
 * @param {number} newRating
 * @return {void}
 */
FoodRatings.prototype.changeRating = function(food, newRating) {
    this.foodRatings.set(food, newRating);
    const cuisine = this.foodToCuisine.get(food);
    this.cuisineToFoods.get(cuisine).push([newRating, food]); // lazy insert
};

/** 
 * @param {string} cuisine
 * @return {string}
 */
FoodRatings.prototype.highestRated = function(cuisine) {
    const heap = this.cuisineToFoods.get(cuisine);
    while (heap.data.length > 0) {
        const [rating, food] = heap.peek();
        if (this.foodRatings.get(food) === rating) {
            return food;
        }
        heap.pop(); // discard outdated entry
    }
    return "";
};

class MaxxHeap {
    constructor() {
        this.data = [];
    }
    push(item) {
        this.data.push(item);
        this._siftUp(this.data.length - 1);
    }
    peek() {
        return this.data[0];
    }
    pop() {
        const top = this.data[0];
        const end = this.data.pop();
        if (this.data.length > 0) {
            this.data[0] = end;
            this._siftDown(0);
        }
        return top;
    }
    _siftUp(idx) {
        while (idx > 0) {
            const parent = Math.floor((idx - 1) / 2);
            if (this._compare(this.data[idx], this.data[parent]) < 0) break;
            [this.data[idx], this.data[parent]] = [this.data[parent], this.data[idx]];
            idx = parent;
        }
    }
    _siftDown(idx) {
        const length = this.data.length;
        while (true) {
            let left = idx * 2 + 1;
            let right = idx * 2 + 2;
            let largest = idx;
            if (left < length && this._compare(this.data[left], this.data[largest]) > 0) largest = left;
            if (right < length && this._compare(this.data[right], this.data[largest]) > 0) largest = right;
            if (largest === idx) break;
            [this.data[idx], this.data[largest]] = [this.data[largest], this.data[idx]];
            idx = largest;
        }
    }
    _compare(a, b) {
        // a and b are [rating, food] — higher rating first, then lexicographically smaller food
        if (a[0] !== b[0]) return a[0] - b[0];
        return b[1] < a[1] ? -1 : (b[1] > a[1] ? 1 : 0);
    }
}
/** 
 * Your FoodRatings object will be instantiated and called as such:
 * var obj = new FoodRatings(foods, cuisines, ratings)
 * obj.changeRating(food,newRating)
 * var param_2 = obj.highestRated(cuisine)
 */