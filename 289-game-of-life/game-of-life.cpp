class Solution {
private:
    int countLiveNeighbours(vector<vector<int>>& board , int row , int col){
        int n     = board.size();
        int m     = board[0].size();
        int count = 0;
        vector<vector<int>> direction = {{-1,0},{0 , 1},{1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};

        for(auto dir:direction){
            int n_row = row+dir[0];
            int n_col = col+dir[1];

            if( n_row >=0 and n_row<n and n_col >= 0 and n_col < m and board[n_row][n_col] == 1){
                count++;
            }
        }
        return count;

    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> temp = board;
        for(int row = 0 ; row<n ; row++){
            for(int col = 0;col < m ; col++){
                int count = countLiveNeighbours(board , row , col);
                cout<<count<<" ";
                if( board[row][col] == 0 and count == 3) temp[row][col] =1;
                else if( board[row][col] == 1){
                    //live 
                    if( count <2 || count > 3){
                        temp[row][col] = 0;
                    }else{
                        temp[row][col] = 1;
                    }
                }
            }
            cout<<endl;
        }
        for(int row = 0 ; row<n ; row++){
            for(int col = 0;col < m ; col++){
                board[row][col] = temp[row][col];
            }
        }
    }
};