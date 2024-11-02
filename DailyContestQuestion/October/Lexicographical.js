// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function(n) {
    const result=[];
    let current =1;
    for(let i=0;i<n;i++){
      result.push(current);
      if(current*10<=n){
          current *=10;
      }else{
          while(current%10 ===9 || current+1>n){
              current=Math.floor(current/10)
          }
          current ++
      }
    }  
    return result;
  };