//TC: O(m*n)
//SC: O(m*n)
//SC: O(min(m,n)) if visited not used


class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited)
    {
        int m=grid.size();
        int n=grid[0].size();
        int area=0;
        visited[row][col]=1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int dRow[]={-1, 0, 0, 1};
        int dCol[]={0, -1, 1, 0};
        while(!q.empty())
        {
            int cRow=q.front().first;
            int cCol=q.front().second;
            area++;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nRow=cRow+dRow[i];
                int nCol=cCol+dCol[i];
                if(nRow>=0 && nCol>=0 && nRow<m && nCol<n && grid[nRow][nCol] && !visited[nRow][nCol])
                {
                    visited[nRow][nCol]=1;
                    q.push({nRow, nCol});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int area=0;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    area=max(area, bfs(i, j, grid, visited));
                }
            }
        }
        return area;
    }
};
