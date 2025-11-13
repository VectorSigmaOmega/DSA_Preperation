//Kahn or TopoSort BFS
// Time Complexity : O(V+E)
// Space complexity : O(V)

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> degree(V, 0);
        //finding degeww
        for(auto i:adj)
        {
            for(auto j : i)
            {
                degree[j]++;
            }
        }
        //adding 0 degree nodes to queue
        queue<int> q;
        for(int i=0; i<V; i++)
        {
            if(degree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int> result;
        
        while(!q.empty())
        {
            int val=q.front();
            q.pop();
            result.push_back(val);
            for(const auto& i : adj[val])
            {
                degree[i]--;
                if(degree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        return result;
    }
};
