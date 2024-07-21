class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int row = 0 ; row< matrix.size(); row++){
            for(int col =0  ; col < matrix[row].size(); col++){
                if( row < col){
                    swap(matrix[row][col] , matrix[col][row]);
                }
            }
        }
        for(auto &vec:matrix){
            reverse(vec.begin() , vec.end());
        }
        
    }
};