class Solution {
public:
    int n;
    int m;
    void bfs(int row , int col , vector<vector<char>>&grid , vector<vector<int>> &vis){
        queue<pair<int,int>> q;
        q.push({row , col});
        vis[row][col] = 1;
        int dx[] = {-1 , 0 , 1, 0};
        int dy[] = {0 , 1 , 0 , -1};
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x     = temp.first;
            int y     = temp.second;
            for(int i = 0 ; i < 4 ; i++){
                int nx= x+dx[i];
                int ny= y+dy[i];

                if( nx >= 0 and nx < n and ny >=0 and ny < m and !vis[nx][ny] and grid[nx][ny] == '1'){
                    vis[nx][ny] = 1;
                    q.push({nx , ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int row = 0 ; row < n ; row++){
            for(int col = 0; col < m ; col++){
                if( grid[row][col] == '1' and !vis[row][col]){
                    count++;
                    bfs(row , col , grid , vis);
                }
            }
        }

        return count;
    }
};