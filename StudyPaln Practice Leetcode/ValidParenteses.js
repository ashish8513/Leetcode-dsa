// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let st = []; // stack
    for(let i = 0; i < s.length; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            // if you've an opening bracket just add it
            st.push(s[i]);
        } else {
            let currClosing = s[i];
            if(st.length == 0) {
                return false;
            }
            if(currClosing == ')' && st[st.length - 1] != '(') {
                return false;
            }
            if(currClosing == '}' && st[st.length - 1] != '{') {
                return false;
            }
            if(currClosing == ']' && st[st.length - 1] != '[') {
                return false;
            }
            st.pop();
        }
    }
    return st.length == 0;  
};