class Solution {
private:
    void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&visited){
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            auto fNode=q.front();
        int x=fNode.first;
        int y=fNode.second;
        q.pop();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newX=x+dx[i];
            int newY=y+dy[i];
            if((newX>=0&&newX<grid.size())
            &&(newY>=0&&newY<grid[0].size())
            &&!visited[newX][newY]
            &&grid[newX][newY]=='1')
            {
                q.push({newX,newY});
                visited[newX][newY]=true;
            }
        }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //creating our 2d visited array
        vector<vector<int>>visited(n,vector<int>(m,0));
        int numOfIslands=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    numOfIslands++;
                    bfs(row,col,grid,visited);
                }
                }
            }
        return numOfIslands;
    }
};