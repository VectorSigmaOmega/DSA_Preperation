// Time Complexity: O(V+E) + O(V)   (basically just DFS)
//
// Space Complexity: O(V) (recusrion stack)

class Solution {
  public:
    void dfs(int node, vector<bool>& visited, stack<int>& st, vector<vector<int>>& edges)
    {
        visited[node]=true;
        for(auto i:edges[node])
        {
            if(!visited[i])
            {
                dfs(i, visited, st, edges);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(i, visited, st, edges);
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
