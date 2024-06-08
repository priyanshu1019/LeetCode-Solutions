class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totalOranges = 0;
        int rottenOranges = 0;
        int time  = 0 ;
        int n  = grid.size();
        int m  = grid[0].size();

        vector<vector<int>> rotten = grid;
        queue<pair<int,int>> q;

        for(int row = 0 ; row<n ; row++)
        {
            for(int col = 0 ; col < m ; col++)
            {
                if( grid[row][col] == 2)
                {
                    totalOranges++;
                    q.push({row , col});
                }
                if( grid[row][col] == 1)
                {
                    totalOranges++;
                }
            }
        }
        cout<<totalOranges<<" "<<q.size()<<endl;
        int dx[] = {-1,0,1,0};
        int dy[] = {0 , 1, 0,-1};
        while(!q.empty())
        {
            int k = q.size();
            rottenOranges += k;
            while(k--)
            {
                auto curr = q.front();
                int x = curr.first;
                int y = curr.second;
                q.pop();

                for(int i = 0 ; i<4 ; i++)
                {
                    int newX = dx[i] + x;
                    int newY = dy[i] + y;

                    if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
            if( !q.empty()) time++;
        }

        return rottenOranges == totalOranges ? time:-1;
    }
};