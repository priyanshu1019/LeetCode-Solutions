class Solution {
public:
    vector<vector<int>> direction = {{-1 ,0},{1,0},{0,1},{0,-1}};
    bool find(vector<vector<char>>&board , int i , int j , int idx , string &word){
        int n= board.size();
        int m = board[0].size();
        if( idx >= word.size()) return true;

        if(  i <0 || j < 0 || j>=m ||i>=n||board[i][j] != word[idx]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &dir:direction){
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            if( find(board , new_i , new_j , idx+1 , word) ){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        if( n*m  < word.size())return false; 
        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if( board[i][j] == word[0] and find(board , i , j , 0 , word)){
                    return true;
                }
            }
        }   
        return false;
    }
};