class Solution {
public:
    int N , M , K;
    int MOD = 1e9+7;
    int dp[51][51][101];
    int helper(int ind , int searchCost , int maxSoFar){

        if( ind == N ){
            return searchCost == K ? 1:0;
        }
        if( dp[ind][searchCost][maxSoFar] != -1)return dp[ind][searchCost][maxSoFar];
        int result = 0;
        for(int i = 1 ; i <= M ; i++){
            if( i > maxSoFar ){
                result = (result + helper(ind+1 , searchCost+1 , i))% MOD;
            }else{
                result = (result + helper(ind+1 , searchCost , maxSoFar)) % MOD;
            }
        }
        return dp[ind][searchCost][maxSoFar]=result % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        //ind , len , maxSoFar;
        memset(dp ,-1 , sizeof(dp));
        return helper(0 , 0 , 0);
    }
};