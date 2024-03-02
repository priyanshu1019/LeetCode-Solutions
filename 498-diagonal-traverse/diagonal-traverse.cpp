class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> result;
        map<int,vector<int>> mp;        
        for(int row = 0; row<n ; row++)
        {
            for(int col = 0 ; col<m ; col++)
            {
                int key = row+col;
                mp[key].push_back(mat[row][col]);
            }
        }
        for(auto &it:mp)
        {
            if( it.first % 2 == 0)
            {
                reverse(it.second.begin() , it.second.end());
            }
            for(auto &x:it.second)
            {
                result.push_back(x);
            }
        }
        return result;
    }
};