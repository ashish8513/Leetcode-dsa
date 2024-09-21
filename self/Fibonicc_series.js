function generateFibonacciSeries(terms) {
    // Check if the number of terms is less than 1
    if (terms <= 0) {
        return [];
    }
    
    // Initialize the first two terms of the Fibonacci series
    let series = [0];
    if (terms > 1) {
        series.push(1);
    }
    
    // Generate the remaining terms of the series
    for (let i = 2; i < terms; i++) {
        let nextTerm = series[i - 1] + series[i - 2];
        series.push(nextTerm);
    }
    
    return series;
}

// Example usage
let numberOfTerms = 10; // Change this value to generate more or fewer terms
console.log(generateFibonacciSeries(numberOfTerms));
