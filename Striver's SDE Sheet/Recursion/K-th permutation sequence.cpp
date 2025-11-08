// https://leetcode.com/problems/permutation-sequence/description/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1, 1);
        for(int i=1; i<=n; i++)
        {
            fact[i]=i*fact[i-1];
        }
        string result;
        string elements;
        int index;
        for(int i=1; i<=n; i++)
        {
            elements.push_back(i+'0');
        }
        --k;
        for(int i=0; i<n; i++)
        {
            index=(int)(k/fact[n-1-i]);
            result.push_back(elements[index]);
            elements.erase(index, 1);
            k=k%fact[n-1-i];
        }
        return result;
    }
};
