class Solution {
public:
    vector<vector<int>> direction {{0,-1},{1,0},{0,1},{-1,0}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0;
        int j = 0;
        queue<vector<int>> q;
        q.push({i , j , k});//starting point
        bool visited[41][41][1601];//to check visited with state 
        memset(visited, false , sizeof(visited));
        
        int steps = 0;
        while( !q.empty())
        {
            int size = q.size();
            while( size--)
            {
                vector<int> temp = q.front();
                q.pop();
                int i = temp[0];
                int j = temp[1];
                int obs = temp[2];
                if( i == n-1 and j == m-1) return steps;
                for(vector<int> & dir:direction)
                {
                    int new_i = dir[0]+i;
                    int new_j = dir[1]+j;
                    if( new_i <0 || new_i >= n || new_j < 0 || new_j >= m) continue;
                    if( grid[new_i][new_j] == 0 and !visited[new_i][new_j][obs])
                    {
                        q.push({new_i,new_j,obs});
                        visited[new_i][new_j][obs] = true;
                    }else if( grid[new_i][new_j] == 1 and obs >= 1 and !visited[new_i][new_j][obs -1])
                    {
                        q.push({new_i,new_j,obs-1});
                        visited[new_i][new_j][obs-1] = true;
                    }
                }
            }
            steps++;

            
        }

        return -1;

    }
};