// You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

// Return the array after sorting it.

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        dabba={}
        for j in arr:
            lp=bin(j).count("1")
            if lp not in dabba:
                dabba[lp]=[j]
            else:
                dabba[lp].append(j)
        vidai=[]
        for j in sorted(list(dabba)):
            vidai+=sorted(dabba[j])
        return vidai
        

        
