// Time Complexity: O(V+E) + O(V)   (basically just DFS)
//
// Space Complexity: O(V) (recusrion stack)

class Solution {
  public:
    void dfs(int node, vector<bool>& visited, stack<int>& st, vector<vector<int>>& adj)
    {
        visited[node]=true;
        for(auto i:adj[node])
        {
            if(!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
