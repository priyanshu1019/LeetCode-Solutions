class Solution {
int helper(int ind,int buy,vector<int> &values,int n,int cap,vector<vector<vector<int>>> &dp){
    if(cap==0){
        return 0;
    }
    if(ind==n){
        //no more profit 
        return 0;
    }
    if(dp[ind][buy][cap]!=-1){
        return dp[ind][buy][cap];
    }
    int profit=0;
    if(buy){
        profit=max(-values[ind]+helper(ind+1,0,values,n,cap,dp),
                    0+helper(ind+1,1,values,n,cap,dp)
                    );
    }else{
        profit=max(values[ind]+helper(ind+1,1,values,n,cap-1,dp)
                    ,0+helper(ind+1,0,values,n,cap,dp));
    }
    return dp[ind][buy][cap]=profit;
}
public:
    int maxProfit(vector<int>& Arr) {
    int n=Arr.size();
    vector<vector<int>> prev(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
                                            
    // As dp array is intialized to 0, we have already covered the base case
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){// We can buy the stock
                    curr[buy][cap] = max(0+prev[0][cap], 
                                -Arr[ind] + prev[1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    curr[buy][cap] = max(0+prev[1][cap],
                                Arr[ind] + prev[0][cap-1]);
                }
            }
        }
        prev=curr;
    }
    
    
    return prev[0][2];
    }
};