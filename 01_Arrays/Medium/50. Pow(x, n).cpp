// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


class Solution {
public:
    double myPow(double x, int n) {

        long long nn = n;

        if(nn < 0){
            nn = -nn;
        }

        double ans = 1;

        while(nn > 0){

            // odd
            if(nn % 2 == 1){
                ans = ans * x;
                nn = nn - 1;
            }

            // even
            else{
                x = x * x;
                nn = nn / 2;
            }
        }

        if(n < 0){
            ans = 1 / ans;
        }

        return ans;
    }
};