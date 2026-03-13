// You are given an integer mountainHeight denoting the height of a mountain.

// You are also given an integer array workerTimes representing the work time of workers in seconds.

// The workers work simultaneously to reduce the height of the mountain. For worker i:

// To decrease the mountain's height by x, it takes workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x seconds. For example:
// To reduce the height of the mountain by 1, it takes workerTimes[i] seconds.
// To reduce the height of the mountain by 2, it takes workerTimes[i] + workerTimes[i] * 2 seconds, and so on.
// Return an integer representing the minimum number of seconds required for the workers to make the height of the mountain 0.

class Solution {
public:
    long long maxHeight(long long T, vector<int>& workerTimes){
        long long total = 0;
        
        for(long long t : workerTimes){
            long long k = (2 * T) / t;
            
            long long x = (sqrt(1 + 4.0 * k) - 1) / 2;
            
            total += x;
            if(total >= 1e5) break;
        }
        
        return total;
    }
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long l = 0, r = 1e18;
        long long ans = r;
        
        while(l <= r){
            long long mid = l + (r - l) / 2;
            
            if(maxHeight(mid, workerTimes) >= mountainHeight){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return ans;
    }
};
