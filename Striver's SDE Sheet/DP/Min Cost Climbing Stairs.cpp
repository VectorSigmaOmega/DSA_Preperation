// TC: O(N)
// SC: O(N)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> memo(n+2, 0);
        memo[n+1]=0;
        memo[n]=0;
        for(int i=n-1; i>=0; i--)
        {
            memo[i]=cost[i]+min(memo[i+1],memo[i+2]);
        }
        return min(memo[0], memo[1]);
    }
};
