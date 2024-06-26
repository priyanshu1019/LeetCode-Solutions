class Solution {

private:
    void bfs(int sr , int sc , int color , vector<vector<int>> &image , vector<vector<int>> &colored)
    {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q ;
        q.push({sr , sc});
        colored[sr][sc] = color;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0 , 1 , 0 , -1};
        
        while(!q.empty())
        {
            auto currNode = q.front();
            q.pop();
            
            int x = currNode.first;
            int y = currNode.second;
            
            for(int i = 0 ; i<4 ; i++)
            {
                int newX = dx[i] + x;
                int newY = dy[i] + y;
                
                if( (newX>=0 and newX< n) and (newY>=0 and newY <m) and (image[newX][newY] == image[sr][sc]) and (colored[newX][newY] !=color))
                {
                    colored[newX][newY] = colored[sr][sc];
                    q.push({newX , newY});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> colored = image;
        if( image[sr][sc] == color)
        {
            return colored;
        }
        bfs(sr , sc , color , image , colored);
        return colored;

    }
};