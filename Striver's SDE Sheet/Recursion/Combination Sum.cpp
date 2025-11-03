// https://leetcode.com/problems/combination-sum/description/
//
// Time Complexity: 
//  max no of branches at a level = N
//  for 2 levels, no of branches = N^2
// for D levels, no of branches = N^D
// D = target/c_min     where c_min is smallest element
//
// Space Complexity: Depth of call stack = D. Max size of temp at depth D = D
//                   Space(stack) + Space(temp) = O(D) + O(D)

class Solution {
public:
    vector<vector<int>> result;
    void findCombination(vector<int>& candidates, int target, int index, long sum, vector<int> temp)
    {
        for(int i=index; i<candidates.size(); i++)
        {
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            if(sum<target)
            {
                findCombination(candidates, target, i, sum, temp);
            }
            else if(sum==target)
            {
                result.push_back(temp);
            }
            sum-=candidates[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        findCombination(candidates, target, 0, 0, temp);
        return result;
    }
};
