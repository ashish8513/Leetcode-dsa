//? Subsets with Products of Distinct Primes

// Given an integer array arr[], count the number of different subsets whose product can be represented as a product of one or more distinct prime numbers.  Two subsets are considered different if the set of chosen array indexes are not same.

// Return the count modulo 109 + 7.

class Solution {
public:
    int countSubsets(vector<int> &arr) {
        const int MOD = 1e9 + 7;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

        vector<int> cnt(31,0);
        for(int x: arr) cnt[x]++;

        vector<long long> dp(1<<10,0);
        dp[0]=1;

        for(int num=2; num<=30; num++){
            if(cnt[num]==0) continue;

            int x=num;
            int mask=0;
            bool ok=true;

            for(int i=0;i<10;i++){
                int p=primes[i];
                if(x%(p*p)==0){
                    ok=false;
                    break;
                }
                if(x%p==0)
                    mask|=(1<<i);
            }

            if(!ok) continue;

            for(int state=(1<<10)-1; state>=0; state--){
                if((state & mask)==0){
                    dp[state|mask]=(dp[state|mask]+dp[state]*cnt[num])%MOD;
                }
            }
        }

        long long ans=0;
        for(int i=1;i<(1<<10);i++)
            ans=(ans+dp[i])%MOD;

        long long mul=1;
        while(cnt[1]--){
            mul=(mul*2)%MOD;
        }

        ans=(ans*mul)%MOD;
        return (int)ans;
    }
};