class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        auto isSafe = [&](int x , int y)
        {
            return x>=0 and x<n and y>=0 and y<m;
        };
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        vector<vector<int>> effort(n , vector<int>( m , 1e9));
        effort[0][0] = 0;
        int dx [] = {-1 , 0 , 1, 0};
        int dy [] = {0 , 1, 0 , -1};
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int x   = pq.top().second.first;
            int y   = pq.top().second.second;
            pq.pop();

            if( x == n-1 and y == m-1 )
            {
                return diff;
            }

            for(int i = 0 ; i< 4 ; i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if( isSafe(nx , ny))
                {
                    int newEffort = max(diff , abs(heights[x][y] - heights[nx][ny]));
                    if(newEffort < effort[nx][ny])
                    {
                        effort[nx][ny] = newEffort;
                        pq.push({newEffort , {nx , ny}});
                    }
                }
            }
        }

        return -1;
    }
};