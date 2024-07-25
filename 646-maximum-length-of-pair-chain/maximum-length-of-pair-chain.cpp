class Solution {
private:
    int helper(vector<vector<int>> &pairs , int ind , int prev , vector<vector<int>> &dp){
        if( ind >= pairs.size()){
            return 0;
        }
        if( dp[ind][prev+1] != -1)return dp[ind][prev+1];
        int len = helper(pairs , ind+1 , prev , dp);
        if( prev == -1|| pairs[ind][0] > pairs[prev][1]){
            len = max(len , 1+helper(pairs , ind+1 , ind , dp));
        }
        return dp[ind][prev+1]=len;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end());
        int n= pairs.size();
        vector<vector<int>> dp( n , vector<int>(n+1 , -1));
        return helper(pairs , 0 , -1 , dp);
    }
};