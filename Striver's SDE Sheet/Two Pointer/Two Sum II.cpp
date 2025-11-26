// TC=O(N)
// SC=O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while(l<r)
        {
            int diff=target-(numbers[l]+numbers[r]);
            if(diff<0)
            {
                r--;
            }
            else if(diff>0)
            {
                l++;
            }
            else
            {
                return {l+1, r+1};
            }
        }
        return {};
    }
};
