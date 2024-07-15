class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int row = 0 ; row<n ; row++){
            for(int col =0 ; col < m ; col++){
                if( matrix[row][col] == 0){
                    for(int k = 0 ; k < m ; k++){
                        if( k != col and matrix[row][k] != 0){
                            matrix[row][k] =1e9;
                        }
                    }

                    for(int k = 0 ; k < n ; k++){
                        if( k!= row and matrix[k][col] != 0){
                            matrix[k][col] = 1e9;
                        }
                    }
                }
            }
        }

        for(int row = 0; row < n ; row++ ){
            for(int col =0 ; col < m ; col++ ){
                if(matrix[row][col] == 1e9){
                    matrix[row][col] =0;
                }
            }
        }
    }
};