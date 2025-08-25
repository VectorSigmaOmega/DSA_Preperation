//https://leetcode.com/problems/subsets-ii/description/
// Time complexity : 2^N * N/2 => N * 2^(N - 1) => N * (1^N)
// Space complexity : N 
class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& currentSubset, int start)
    {
        result.push_back(currentSubset);
        for(int i=start; i<nums.size(); i++)
        {
            if(i==start || nums[i]!=nums[i-1])
            {
                currentSubset.push_back(nums[i]);
                backtrack(nums, result, currentSubset, i+1);
                currentSubset.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        sort(nums.begin(), nums.end());
        backtrack(nums, result, currentSubset, 0);
        return result;
    }
};  
