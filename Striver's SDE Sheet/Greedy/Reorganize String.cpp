//https://leetcode.com/problems/reorganize-string/description/

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for(auto const c : s)
        {
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto const i : freq)
        {
            pq.push({i.second, i.first});
        }
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
        return new_s;
    }
};
