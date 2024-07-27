class Solution {
public:
    int ans ,obstacle_count;
    int n , m;
    vector<vector<int>> direction = {{-1,0} , {0,1},{0,-1},{1,0}};
    void solve(int row , int col , vector<vector<int>>&grid ,  int count){
         
        if( row >= n || col >= m || row < 0 || col < 0 || grid[row][col] == -1 )return;
        if( grid[row][col] == 2){
            if(count == obstacle_count){
                ans++;
            }
            return;
        }
        grid[row][col] = -1;
        for(auto &dir:direction){
            int n_row = row+dir[0];
            int n_col = col+dir[1];
            solve(n_row , n_col , grid , count+1);
        }
        grid[row][col] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        obstacle_count = 0;
        ans = 0;
        n = grid.size();
        m = grid[0].size();
        int start_i=0 ,start_j=0;
        for(int i =0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                if( grid[i][j] == 0)obstacle_count++;
                if( grid[i][j] == 1){
                    start_i = i; 
                    start_j = j;
                }
            }
        }
        obstacle_count+=1;
        solve(start_i, start_j , grid  , 0);
        return ans;
        
    }
};