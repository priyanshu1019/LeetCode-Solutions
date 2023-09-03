class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &visited){
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
    if (grid[nrow][ncol] == 1 && visited[nrow][ncol]==0) {
        dfs(nrow, ncol, grid, visited);
    }
}

        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1||j==0||j==m-1) && (grid[i][j]==1) && !visited[i][j]){
                    dfs(i,j,grid,visited);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};