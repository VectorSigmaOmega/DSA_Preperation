//https://leetcode.com/problems/subsets-ii/description/
// Time complexity : 2^N * N/2 => N * 2^(N - 1) => N * (2^N)
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

// pattern 2

//pick / don't pick

class Solution {
public:
    vector<vector<int>> result;
    void findSubsets(vector<int>& nums, int index, vector<int>& temp)
    {
        if(index==nums.size())
        {
            result.push_back(temp);
            return ;
        }
        //take the element at index
        temp.push_back(nums[index]);
        findSubsets(nums, index+1, temp);
        temp.pop_back();

        //do not take the element at index
        while(index<nums.size()-1 && nums[index]==nums[index+1])
        {
            //if we decide to not take an element, make sure no copies of that element aren't taken either
            index++;
        }
        findSubsets(nums, index+1, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        findSubsets(nums, 0, temp);
        return result;
    }
};
