// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 /**
 * @param {number} numerator
 * @param {number} denominator
 * @return {string}
 */
var fractionToDecimal = function(numerator, denominator) {
    if(!numerator) return '0';
    
    let str = '';
    
    if(Math.sign(numerator) !== Math.sign(denominator)) str += '-';
    
    const numer = Math.abs(numerator)
    const denom = Math.abs(denominator)
    
    str += Math.floor(numer/denom);
    let rem = numer%denom;
    if(!rem) return str;
    str += '.'
    
    const map = new Map();
    
    while(rem !== 0) {
        map.set(rem, str.length);
        
        rem *= 10;
        str += Math.floor(rem/denom);
        rem %= denom
        
        if(map.has(rem)) {
            const idx = map.get(rem);
            return str.slice(0, idx) + `(${str.slice(idx)})`; 
        }
    }
    return str;
};