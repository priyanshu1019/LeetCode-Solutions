class Solution {
private:
    void dfs( int x , int y , vector<vector<int>> &vis , vector<vector<char>> &mat)
    {
        vis[x][y] = 1;

        int n = mat.size();
        int m = mat[0].size();

        int dx[] = {-1 , 0 , 1, 0};
        int dy[] ={ 0 , 1, 0, -1};

        for(int i =0 ; i< 4 ; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny <m && mat[nx][ny] == 'O' && !vis[nx][ny] )
            {
                dfs(nx , ny , vis , mat);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n , vector<int> ( m , 0));

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(  board[i][j] == 'O' && (i==0 || i == n-1 || j == m-1 || j== 0) && !vis[i][j] )
                {
                    dfs(i , j , vis , board);
                }
            }
        }

        for(int row = 0 ; row < n ; row++)
        {
            for(int col = 0 ; col < m ; col++)
            {
                if( !vis[row][col] && board[row][col] == 'O')
                {
                    board[row][col] = 'X';
                }
            }
        }
    }
};