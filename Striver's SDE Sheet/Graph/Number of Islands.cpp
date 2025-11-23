// Time Complexity: O(N*M)
// Space Complexity: O(N*M) + O(min(N, M))  
// Consider starting point to be corner of a grid. The queue stores the frontier wavefront. This is a diagonal. The max length of this diagonal would be
// min(N, M). Draw a grid and try it out.


class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        visited[i][j]=1;
        queue<pair<int, int>> q;
        int dRow[]={-1, 0, 0, 1};
        int dCol[]={0, -1, 1, 0};
        q.push({i, j});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0; k<4; k++)
            {
                int nrow=row+dRow[k];
                int ncol=col+dCol[k];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    count++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};
