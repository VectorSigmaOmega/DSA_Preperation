// Time complexity : O(2^n)
// Space complexity : O(n) 

class Solution {
public:
    int findStep(int n)
    {
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return 1;
        }
        return findStep(n-1) + findStep(n-2);
    }
    int climbStairs(int n) {
        return findStep(n);
    }
};
