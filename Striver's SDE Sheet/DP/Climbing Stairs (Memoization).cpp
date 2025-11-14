// Time Complexit: O(N)
// Space Compleixty: O(N)

class Solution {
public:
    int findStep(int n, vector<int>& dp)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n] = findStep(n-1, dp) + findStep(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0]=1;
        dp[1]=1;
        return findStep(n, dp);
    }
};
