// TC : O(N)
// SC : O(N)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n+2, 0);
        for(int i=n-1; i>=0; i--)
        {
            memo[i]=max(nums[i]+memo[i+2], memo[i+1]);
        }
        return memo[0];
    }
};
