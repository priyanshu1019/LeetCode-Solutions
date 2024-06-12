class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if( n == 0 || grid[0][0] != 0)
        {
            return -1;
        }

        auto isSafe = [&](int x , int y)
        {
            return x>=0 and x<n and y<n and y>=0;
        };
        priority_queue<pair<int,pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0 , { 0 , 0}});

        int dx[] = {-1 , 0 , 1, 0  , 1 , 1 , -1 , -1};
        int dy[] = {0 , 1 , 0 , -1 , 1 , -1 , -1 , 1};
        vector<vector<int>> dist( n , vector<int>( n , INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int x   = pq.top().second.first;
            int y   = pq.top().second.second;
            pq.pop();

            if( x == n-1 and y == n-1) //it means we are at our dest
                return dis+1;
            
            for(int i =0; i<8 ; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if( isSafe(nx , ny) && grid[nx][ny] == 0 && dis+1<dist[nx][ny])
                {
                    dist[nx][ny] = 1+dis;
                    pq.push({dist[nx][ny] , {nx , ny}});
                }
            }
        }

        return -1;
    }
};