class Solution {
private:
    int helper(int n,vector<int> &dp){
        if(n<=1) return n;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=helper(n-1,dp)+helper(n-2,dp);
    }
public:
    int fib(int n) {
        vector<int> dp(n+2,-1);
        // return helper(n,dp);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};