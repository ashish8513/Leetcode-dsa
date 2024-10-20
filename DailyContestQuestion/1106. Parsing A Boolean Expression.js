// A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

// 't' that evaluates to true.
// 'f' that evaluates to false.
// '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
// '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
// '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
// Given a string expression that represents a boolean expression, return the evaluation of that expression.

// It is guaranteed that the given expression is valid and follows the given rules.



/**
 * @param {string} expression
 * @return {boolean}
 */
function parseBoolExpr(expression) {
    // Function to evaluate logical AND (&)
    const evaluateAnd = (exprs) => exprs.every(e => e === true);

    // Function to evaluate logical OR (|)
    const evaluateOr = (exprs) => exprs.some(e => e === true);

    // Function to evaluate logical NOT (!)
    const evaluateNot = (expr) => !expr;

    // Recursive function to evaluate the expression
    function evaluate(expr) {
        if (expr === 't') return true;  // True literal
        if (expr === 'f') return false; // False literal

        let i = 0;
        if (expr[i] === '!') {  // NOT expression
            return evaluateNot(evaluate(expr.slice(2, -1)));
        }

        let op = expr[i];  // Get the operator (either & or |)
        let args = [], balance = 0, currentExpr = "";

        for (let j = 2; j < expr.length - 1; j++) {
            if (expr[j] === '(') balance++;  // Track nested parentheses
            if (expr[j] === ')') balance--;
            if (expr[j] === ',' && balance === 0) {
                args.push(evaluate(currentExpr)); // Evaluate the subexpression
                currentExpr = ""; // Reset for the next one
            } else {
                currentExpr += expr[j];
            }
        }

        if (currentExpr) {
            args.push(evaluate(currentExpr)); // Last subexpression
        }

        if (op === '&') {
            return evaluateAnd(args);
        } else if (op === '|') {
            return evaluateOr(args);
        }

        throw new Error("Invalid operation");
    }

    return evaluate(expression);
}

// Test examples:
console.log(parseBoolExpr("!(f)")); // true
console.log(parseBoolExpr("|(f,t)")); // true
console.log(parseBoolExpr("&(t,f)")); // false
console.log(parseBoolExpr("|(&(t,f,t),!(t))")); // false
