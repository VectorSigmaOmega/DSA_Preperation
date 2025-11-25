// TC = O(N)
// SC = O(1)

class Solution {
public:
    int find(int start, int end, vector<int>& nums)
    {
        int pprev = 0;
        int prev = 0;
        int current = 0;
        for(int i=end-1; i>=start; i--)
        {
            current=max(nums[i]+pprev, prev);
            pprev=prev;
            prev=current;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        return max(find(0, n-1, nums), find(1, n, nums));
    }
};
