// https://leetcode.com/problems/permutations/description/
// Time complexity: O(n!*n) + O(n!*n) = O(n!*n)
// Space complexity: O(n+n)

class Solution {
public:
    vector<vector<int>> result;
    void findPermutations(vector<int>& nums, vector<int>& temp)
    {
        if(nums.size()==0)
        {
            result.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            int tempVal=nums[i];
            nums.erase(nums.begin()+i);
            temp.push_back(tempVal);
            findPermutations(nums, temp);
            temp.pop_back();
            nums.insert(nums.begin()+i, tempVal);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        findPermutations(nums, temp);
        return result;
    }
};


// Time complexity: O(n!*n) + O(n!*n) = O(n!*n)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> result;
    void findPermutations(vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            findPermutations(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        findPermutations(nums, 0);
        return result;
    }
};


