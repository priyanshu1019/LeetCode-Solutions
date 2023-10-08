class Solution {
private:
    int helper(int ind,int prevInd,vector<vector<int>>& nums,vector<vector<int>> &dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind][prevInd+1]!=-1){
            return dp[ind][prevInd+1];
        }
        //not pick
        int len=0+helper(ind+1,prevInd,nums,dp);
        //pick
        if(prevInd==-1||nums[ind][0]>nums[prevInd][1]){
            len=max(len,1+helper(ind+1,ind,nums,dp));
        }
        return dp[ind][prevInd+1]=len;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        sort(begin(pairs),end(pairs));
        return helper(0,-1,pairs,dp);
    }
};