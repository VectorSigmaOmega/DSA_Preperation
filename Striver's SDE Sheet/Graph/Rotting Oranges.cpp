// TC : O(M*N)
// SC: O(M*N)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        queue<pair<pair<int, int>, int>> q;
        int count=0, time=0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j]=1;
                }
                else if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        int dRow[]={-1, 0, 0, 1};
        int dCol[]={0, -1, 1, 0};
        while(!q.empty())
        {
            int cRow=q.front().first.first;
            int cCol=q.front().first.second;
            int cTime=q.front().second;
            time=max(time, cTime);
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nRow=cRow+dRow[i];
                int nCol=cCol+dCol[i];
                if(nRow>=0 && nCol>=0 && nRow<row && nCol<col && !visited[nRow][nCol] && grid[nRow][nCol]==1)
                {
                    visited[nRow][nCol]=1;
                    q.push({{nRow, nCol}, cTime+1});
                    count--;
                }
            }
        }
        if(count!=0)
        {
            return -1;
        }
        return time;
    }
};
