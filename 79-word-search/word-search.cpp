class Solution {
private:
    int n , m;
    vector<vector<int>>direction  = {{-1,0},{0,1},{0,-1},{1,0}};
    bool find(int i , int j ,int ind, vector<vector<char>>& board , string &word){
        if( ind == word.size())return true;
        if( i < 0 || i >= n || j < 0 || j >= m ||board[i][j] == '$'|| board[i][j] != word[ind]) return false;

        char temp   = board[i][j];
        board[i][j] = '$';

        for(auto &dir : direction){
            int n_i = i+dir[0];
            int n_j = j+dir[1];
            if( find(n_i , n_j , ind+1 , board , word) == true)return true;
        } 
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if( board[i][j] == word[0] and find(i , j ,0, board , word)){
                    return true;
                }
            }
        }

        return false;
    }
};