// TC = O(N)
// SC = O(N+2)

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n==0 || s[0]=='0')
        {
            return 0;
        }
        vector<int> memo(n+2, 0);
        memo[n]=1;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]!='0')
            {
                memo[i]+=memo[i+1];
            }
            if(i<n-1 && ( (s[i+1]<='6' && s[i]=='2') || s[i]=='1' ))
            {
                memo[i]+=memo[i+2];
            }
        }
        return memo[0];
    }
};
