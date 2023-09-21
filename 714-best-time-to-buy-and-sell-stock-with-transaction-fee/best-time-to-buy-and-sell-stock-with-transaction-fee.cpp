class Solution {
int helper(int ind,int buy,vector<int> &values,int n,vector<vector<int>> &dp,int fee){
    if(ind>=n){
        //no more profit 
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    int profit=0;
    if(buy){
        profit=max(-values[ind]+helper(ind+1,0,values,n,dp,fee),
                    0+helper(ind+1,1,values,n,dp,fee)
                    );
    }else{
        profit=max(values[ind]+helper(ind+1,1,values,n,dp,fee)-fee
                    ,0+helper(ind+1,0,values,n,dp,fee));
    }
    return dp[ind][buy]= profit;
}
public:
    int maxProfit(vector<int>& values, int fee) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,1,values,n,dp,fee);
    }
};