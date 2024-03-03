class Solution {
    int countOverlaps(vector<vector<int>> &A , vector<vector<int>> &B , int rowOffset , int colOffset)
    {
        int count = 0;
        int n = A.size();

        for(int i = 0 ; i<n ; i++ )
        {
            for(int j = 0 ; j<n ; j++)
            {
                int B_i = i + rowOffset;
                int B_j = j + colOffset;
                
                if( B_i <0 || B_i >=n || B_j <0 || B_j >= n) 
                    continue;
                if( A[i][j] == 1 and B[B_i][B_j] == 1 )
                {
                    count++;
                }
            }
        }
            return count;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int maxOverlap = 0;
        int n          = A.size();

        for(int rowOffset = -n+1 ; rowOffset < n ; rowOffset++)
        {
            for(int colOffset = -n + 1 ; colOffset < n ; colOffset++)
            {
                int count = countOverlaps(A , B , rowOffset , colOffset);
                maxOverlap = max(count , maxOverlap);
            }
        }
        return maxOverlap;

    }
};