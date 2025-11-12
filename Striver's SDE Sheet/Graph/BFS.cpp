// Time Complexity: O(V+E)
// each node is visited once. So O(V)
// deg(0)+deg(1)+...deg(V) = 2*E
// So, O(V+E)
//
// Space complexity ; O(V)  In worst case (star), the queue might have to hold almost all vertices (V-1) at the same time. 
// This means the queue requires O(V) space.

class Solution {
  public:
        vector<int> bfs(vector<vector<int>> &adj) {
        vector<bool> visited(adj.size(), false);
        vector<int> result;
        queue<int> q;
        q.push(0);
        visited[0]=true;
        //visited when in queue
        while(!q.empty())
        {
            int val=q.front();
            result.push_back(val);
            q.pop();
            //pop when printed
            for(int i : adj[val])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        return result;
    }
};
