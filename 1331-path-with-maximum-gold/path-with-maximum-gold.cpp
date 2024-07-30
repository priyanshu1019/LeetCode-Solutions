class Solution {
public:
    vector<vector<int>> direction = {{-1 , 0 }, {0,1},{0,-1},{1,0}};
    int solve(int i , int j , vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if( i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || grid[i][j] == -1 ){
            return 0;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        int ans = 0;
        for(auto &dir : direction){
            int nx = i+dir[0];
            int ny = j+dir[1];
            ans    = max(ans , solve(nx , ny , grid));
        }
        grid[i][j] = temp;
        return ans+grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if( grid[i][j] != 0){
                    ans = max(ans , solve(i , j , grid));
                }
            }
        }
        
        return ans;
    }
};