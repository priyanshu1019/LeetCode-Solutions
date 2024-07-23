class Solution {
private:
    int helper( string &s , string &t , int i , int j , vector<vector<int>> &dp){
        if( j >= t.size()){
            //match 
            return 1;
        }
        if( i >= s.size()){
            // no possibility 
            return 0;
        }
        if( dp[i][j] != -1){
            return dp[i][j];
        }
        //two cases either match or no match 
        //first case match 
        int match = 0;
        int noMatch = 0;
        if( s[i] == t[j]){
            match = helper(s , t , i+1 , j+1 , dp) + helper(s , t , i+1 ,j,dp);
        }else{
            noMatch = helper(s , t , i+1 , j,dp);
        }
        return dp[i][j]=match + noMatch;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(1001 , vector<int>(1001 , -1));
        return helper(s , t , 0 , 0 , dp);
    }
};