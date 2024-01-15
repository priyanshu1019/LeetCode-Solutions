class Solution {
public:
    int dp[21][21];
    bool helper(int i , int j , string &s , string &p )
    {
        if( i>=s.size() and j >= p.size() ) return true;
        if( j>= p.size()) return false;
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        bool match = i < s.size() and (s[i] == p[j] or p[j] == '.');

        if( j+1 < p.size() and p[j+1] == '*')
        {
            return dp[i][j] = helper(i  , j+ 2, s , p) or (match and helper(i+1 , j , s , p));
        }
        if(match)
        {
            return dp[i][j] = helper(i+1 , j+1 , s , p);
        }
        return dp[i][j] = false;

    }
    bool isMatch(string s, string p) {
        memset(dp , -1 , sizeof(dp));
       return  helper(0,0,s,p);
    }
};