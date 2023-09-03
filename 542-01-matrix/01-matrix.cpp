class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        //ready with the matrix
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        //now my queue has all the ones with there initial distance 0
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int d=q.front().second;
            q.pop();
            dist[row][col]=d;
            //now i want to traverse the neighbours
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},d+1});
                }
            }
        }
        return dist;
    }
};