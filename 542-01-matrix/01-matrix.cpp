class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n , vector<int>(m ,0));
        vector<vector<int>> dist(n , vector<int>(m , 0));

        queue<pair<int , pair<int,int>>> q;

        for(int i =0 ; i< n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({0 , { i , j}});
                    vis[i][j] = 1;
                }
            }
        }

        int dx[] = {-1 , 0 , 1, 0};
        int dy[] = {0 , 1, 0 , -1};

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int dis = node.first;
            int x   = node.second.first;
            int y   = node.second.second;

            dist[x][y] = dis;
            for(int i =0 ; i<4 ; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];

                if( (nx >= 0 and nx < n ) && (ny >= 0 and ny < m) 
                && !vis[nx][ny] && mat[nx][ny] == 1 )
                {

                    vis[nx][ny] = 1;
                    q.push({dis+1 , {nx , ny}});
                }
            }
        }

        return dist;
    }
};