// Time Complexit: O(N)
// Space Compleixty: O(N)

class Solution {
public:
    int findStep(int n, vector<int>& dp)
    {
        if(n<=1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n] = findStep(n-1, dp) + findStep(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return findStep(n, dp);
    }
};
