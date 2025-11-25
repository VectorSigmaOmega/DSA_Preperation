// TC: O(N^2)
// SC: O(N)

class Solution {
public:
    string expand(string s, int left, int right)
    {
        int n=s.length();
        while(left>=0 && right<n && s[left]==s[right])
        {
            left--;
            right++;
        }
        return s.substr(left+1, right-1-left);
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0; i<s.length(); i++)
        {
            string odd=expand(s, i, i);
            if(odd.length()>ans.length())
            {
                ans=odd;
            }
            string even=expand(s, i, i+1);
            if(even.length()>ans.length())
            {
                ans=even;
            }
        }
        return ans;
    }
};
