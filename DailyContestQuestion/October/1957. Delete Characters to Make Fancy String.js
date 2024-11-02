// A fancy string is a string where no three consecutive characters are equal.

// Given a string s, delete the minimum possible number of characters from s to make it fancy.

// Return the final string after the deletion. It can be shown that the answer will always be unique

/**
 * @param {string} s
 * @return {string}
 */
var makeFancyString = function(s) {
    let res=''
   let ls='.'
   let count=0
   for(let i=0;i<s.length;i++){
       if(s[i]==ls)count++
       else {
           count=1
           ls=s[i]
       }

       if(count>2){
           continue
       }
       res+=s[i]
   }
   return res
};