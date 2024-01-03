class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = m-1;

        while( low < n and high >= 0 )
        {
            int sum = matrix[low][high] ;
            if( sum  == target ){
                return true;
            }
            else if( sum < target ){
                low++;
            }
            else if( sum > target ){
                high--;
            }
        }

        return false;
        
    }
};