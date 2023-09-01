class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int iniColor, int color) {
        ans[row][col] = color;
        queue<pair<int, int>> q;
        int n = ans.size();
        int m = ans[0].size();
        q.push({row, col});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if ((newX >= 0 && newX < n) && (newY >= 0 && newY < m) && ans[newX][newY] == iniColor && ans[newX][newY] != color) {
                    ans[newX][newY] = color;
                    q.push({newX, newY});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        // Store the matrix because we want to fill colors so the matrix will change
        vector<vector<int>> ans = image;
        bfs(sr, sc, image, ans, iniColor, color);
        return ans;
    }
};
