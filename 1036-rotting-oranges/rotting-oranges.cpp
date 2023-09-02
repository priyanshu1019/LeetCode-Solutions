class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        vector<vector<int>> ans = grid; 
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j},0});
                    ans[i][j]==2;
                }
            }
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
                auto node = q.front();
                int x = node.first.first;
                int y = node.first.second;
                time=max(time,node.second);
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    if ((newX >= 0 && newX < ans.size()) && 
                    (newY >= 0 && newY < ans[0].size()) &&
                     ans[newX][newY] != 2 && ans[newX][newY] == 1) {
                        ans[newX][newY] = 2;
                        q.push({{newX, newY},node.second+1});
                    }
                }
            
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(ans[i][j]!=2 && ans[i][j]!=0){
                    return -1;
                }
            }
        }
        return time;
    }
};
