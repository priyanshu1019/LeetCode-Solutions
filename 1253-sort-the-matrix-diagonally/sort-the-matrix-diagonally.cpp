class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int,vector<int>> mp;
        for(int row = 0 ; row<n ; row++)
        {
            for(int col = 0 ; col < m ; col++ )
            {
                int key = row-col;
                mp[key].push_back(mat[row][col]);
            }
        }
        
        // sort them in non decreasing order
        for(auto &it: mp)
        {
            sort(it.second.begin(),it.second.end() );
        }
        //putback
        for(int row = n-1 ; row>=0 ; row--)
        {
            for(int col = m-1 ; col>=0 ; col-- )
            {
                int key = row-col;
                mat[row][col] = mp[key].back();
                mp[key].pop_back();
            }
        }
        return mat;

    }
};