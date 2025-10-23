//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
//time complexity: O(n) (jobs) + O(nlogn) (sorting) + O(n) (parent array iota initialisation) + n*O( a(n) )
//where a(n) is the inverse Ackermann function, which grows so slowly that it's considered almost constant (O(1)).The "union" (the assignment) is part of this cost.

//space complexity: O(n) (stack) + O(n) (jobs pair vector) +O(n) (parent vector)
#include <numeric>

class Solution {
  private:
    vector<int> parent;
    int find(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return parent[i]=find(parent[i]);
    }
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int, int>> jobs;
        int maxTime=0;
        for(int i=0; i<deadline.size(); i++)
        {
            maxTime=max(maxTime, deadline[i]);
            jobs.push_back({profit[i], deadline[i]});
        }
        sort(jobs.begin(), jobs.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.first==b.first)
            {
                return a.second > b.second;
            }
            return a.first > b.first;
        });
        int totalProfit=0;
        int free;
        int count=0;
        parent.resize(maxTime+1);
        iota(parent.begin(), parent.end(), 0);
        for(const auto i:jobs)
        {
            free = find(i.second);
            if(free>0)
            {
                totalProfit+=i.first;
                count++;
                //union
                parent[free]=find(free-1);
            }
        }
        return {count, totalProfit};
    }
};
