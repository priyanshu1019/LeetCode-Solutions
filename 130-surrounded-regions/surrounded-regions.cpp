class Solution {
private:
    void dfs(int row,int col,vector<vector<char>> &board,vector<vector<int>> &visited,int dx[],int dy[]){
        int n=board.size();
        int m=board[0].size();
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O'&& !visited[nrow][ncol]){
                dfs(nrow,ncol,board,visited,dx,dy);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||j==0||i==n-1||j==m-1)&&(board[i][j]=='O')&& !visited[i][j]){
                    dfs(i,j,board,visited,dx,dy);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&!visited[i][j]){
                    board[i][j]='X';
                }
            }
        }

    }
};