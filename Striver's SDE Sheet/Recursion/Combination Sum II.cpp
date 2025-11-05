// https://leetcode.com/problems/combination-sum-ii/
// Time Complexity: N*2^N , since no duplicates allowed, max 2^N subsets
// Space complexity: N+N  , depth of stack is N

class Solution {
public:
    vector<vector<int>> result;
    void findCombination(vector<int>& candidates, int target, int index, vector<int>& temp)
    {
        if(target==0)
        {
            result.push_back(temp);
        }
        for(int i=index; i<candidates.size(); i++)
        {
            if(target<candidates[i])
            {
                break;
            }
            if(i==index || candidates[i]!=candidates[i-1])
            {
                temp.push_back(candidates[i]);
                findCombination(candidates, target-candidates[i], i+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findCombination(candidates, target, 0, temp);
        return result;
    }
};
