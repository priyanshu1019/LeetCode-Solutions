class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> mat = matrix;
        int n= mat.size();
        int m= mat[0].size();
        for(int i = 0 ; i< n ; i++)
        {
            for(int j = 0 ; j<m;j++)
            {
                mat[i][j] = matrix[j][i];
                mat[j][i] = matrix[i][j];
            }
        }
        matrix = mat;
        for(auto &vec:matrix)
        {
            reverse(vec.begin() ,  vec.end());
        }
        
    }
};