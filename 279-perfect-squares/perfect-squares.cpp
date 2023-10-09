class Solution {
private:
    int dp[10001];
    int helper(int n){
        if(n==0){
            //it means we dont need any no of perfect square
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int miniCost=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int result=1+helper(n-(i*i));
            miniCost=min(result,miniCost);
        }
        return dp[n]=miniCost;
    }
public:
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n);
    }
};