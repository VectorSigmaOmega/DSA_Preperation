// TC: O(N^2) + O(NlogN)
// SC: O((N-1)*3) = O(N)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l, r, n=nums.size(), sum=0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i=0; i<n-2; i++)
        {
            if(nums[i]>0)
            {
                break;
            }
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            l=i+1, r=n-1;
            while(l<r)
            {
                sum=nums[i]+nums[l]+nums[r];
                if(sum>0)
                {
                    r--;
                }
                else if(sum<0)
                {
                    l++;
                }
                else
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1])
                    {
                        l++;
                    }
                    while(l<r && nums[r]==nums[r-1])
                    {
                        r--;
                    }
                    l++;
                    r--;
                }
            }
        }
        return result;
    }
};
