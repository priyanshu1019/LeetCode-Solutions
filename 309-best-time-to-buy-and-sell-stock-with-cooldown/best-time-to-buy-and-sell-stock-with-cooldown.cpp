class Solution {
private:
int helper(int ind,int buy,vector<int> &values,int n,vector<vector<int>> &dp){
    if(ind>=n){
        //no more profit 
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    int profit=0;
    if(buy){
        profit=max(-values[ind]+helper(ind+1,0,values,n,dp),
                    0+helper(ind+1,1,values,n,dp)
                    );
    }else{
        profit=max(values[ind]+helper(ind+2,1,values,n,dp)
                    ,0+helper(ind+1,0,values,n,dp));
    }
    return dp[ind][buy]= profit;
}
public:
    int maxProfit(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,1,values,n,dp);
    }
};