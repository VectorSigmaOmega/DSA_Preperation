// Time complexity:
// visited[i] ensures that each node is visited only once so, O(V)
// for a node n, its connected edges are iterated upon for deg(n)
// by handshake lemma, deg(0) + deg(1) + ... deg(n) = 2E for undirected graph
// So O(V+ 2E) = O(V+E)
//
// Space complexity : O(V)(recursion stack) + O(V)(numbers) + O(V)(visited = O(V))

class Solution {
public:
    vector<int> result;
    vector<bool> visited;
    vector<vector<int>> member_adj; 
    void traversal(int node) {
        visited[node] = true;
        result.push_back(node);
        for (auto i : member_adj[node]) {
            if (!visited[i]) {
                traversal(i);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        
        this->member_adj = adj; 
        int V = adj.size();
        visited.resize(V, false);
        traversal(0);
        return result;
    }
};
