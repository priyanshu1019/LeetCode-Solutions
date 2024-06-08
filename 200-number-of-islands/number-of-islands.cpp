class Solution {
private:

    void bfs(int row , int col , vector<vector<int>>& vis , vector<vector<char>> &grid)
    {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row , col});
        int n  = grid.size();
        int m  = grid[0].size();
        while(!q.empty())
        {
            auto currNode = q.front();
            q.pop();

            int currRow = currNode.first;
            int currCol = currNode.second;

            int dx[] = {-1 , 0 , 1 , 0};
            int dy[] = {0 , 1 , 0 , -1};

            for(int i = 0 ; i < 4 ; i++)
            {
                int newX = currRow+dx[i];
                int newY = currCol+dy[i];

                if( (newX >= 0 and newX < n ) && (newY >=0 and newY <m ) 
                && grid[newX][newY] == '1' && !vis[newX][newY] )
                {
                    vis[newX][newY] = 1;
                    q.push({newX , newY});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        int n     = grid.size();
        int m     = grid[0].size();
        
        vector<vector<int>> vis( n , vector<int>(m , 0));

        for(int row = 0 ; row<n ; row++)
        {
            for(int col = 0 ; col < m ;col++)
            {
                if( grid[row][col] == '1' and !vis[row][col]  )
                {
                    count++;
                    bfs(row ,col , vis , grid);
                }
            }
        }

        //return result
        return count;
    }
};