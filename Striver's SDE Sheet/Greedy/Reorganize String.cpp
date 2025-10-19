//https://leetcode.com/problems/reorganize-string/description/

//Time complexity: 

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for(auto const c : s)
        {
            freq[c]++;
        }
        //O(n)
        priority_queue<pair<int, char>> pq;
        for(auto const i : freq)
        {
            pq.push({i.second, i.first});
        }
        //O(logk) for insertion.
        //assume k unique chars
        //O(klogk)
        if(pq.top().first>(s.length()+1)/2)
        {
            return "";
        }
        string new_s;
        pair<int, char> current, prev = {0, '#'};
        while(!pq.empty())
        {
            current=pq.top();
            new_s+=current.second;
            pq.pop();
            if(prev.first>0)
            {
                pq.push(prev);
            }
            current.first--;
            prev=current;
        }
        //Pop: O(log k)
        //Push: O(log k)
        //n*(1 + logk + logk) = n*O(log k) [1 term does not grow] = O(nlogk) [k is limited to 26 at max, so k is const] = O(n)
        //total O(n+ klogk+n) = O(n)
        
        // time complexity = O(n)
        //space complexity = O(k+k+n)=O(n) (hashmap + heap + string)
        return new_s;
    }
};
