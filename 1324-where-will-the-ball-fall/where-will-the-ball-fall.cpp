class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> answer;

        for(int ball = 0 ; ball < m ; ball++)
        {
            int row = 0;
            int col = ball;
            bool blocked = false;
            while(row < n and col < m)
            {
                if( grid[row][col] == 1)
                {
                    if( col == m-1 || grid[row][col+1] == -1)
                    {
                        blocked = true;
                        break;
                    }else{
                        col++;
                    }
                }else{
                    if( col == 0 || grid[row][col-1] == 1)
                    {
                        blocked = true;
                        break;
                    }else{
                        col--;
                    }
                }
                row++;
            }
            if( blocked == true)
            {
                answer.push_back(-1);
            }else{
                answer.push_back(col);
            }
        }
        return answer;
    }
};