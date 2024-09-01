class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if( m * n != original.size())return {};
        vector<vector<int>> result( m , vector<int>( n ));
        int i =0 ;

        for(int row = 0; row < m ; row++){
            for(int col =0 ; col < n ; col++){
                result[row][col] = original[i++];
            }
        }
        return result;
    }
};