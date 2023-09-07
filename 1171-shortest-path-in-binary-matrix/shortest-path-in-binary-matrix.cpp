class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }

        int n=grid.size();
        if(grid[n-1][n-1]!=0){
            return -1;
        }
        queue<pair<int,pair<int,int>>> pq;
        pq.push({1,{0,0}});
        // grid[0,0]
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=0;
        int dx[] = {-1, 0, +1, 0, 1, -1, -1, 1};
        int dy[] = {0, 1, 0, -1, 1, 1, -1, -1}; 
        while(!pq.empty()){
            auto it=pq.front();
            int dis=it.first;
            int x=it.second.first;
            int y=it.second.second;
            
            pq.pop();
            if(x==n-1 && y==n-1){
                return dis;
            }
            //traverse karna hai 
           for(int i=0;i<8;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==0 && dis+1<dist[newX][newY]){
                    dist[newX][newY]=dis+1;
                    pq.push({dist[newX][newY],{newX,newY}});
                }
           }
        }
        return -1;
    }
};