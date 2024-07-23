class Solution {
private:
    int helper( vector<int>& nums ,  int ind, vector<int>&dp){
        if( ind >= nums.size()){
            return 0;
        }
        if( dp[ind] != -1) return dp[ind];
        int take = nums[ind] + helper(nums , ind+2 , dp);
        int notTake = helper(nums , ind+1 , dp);

        return dp[ind] = max(take , notTake);

    }
public:
    int rob(vector<int>& nums) {
        int prev = -1;
        int n= nums.size();
        vector<int> dp(n+1 , -1);
        return helper( nums  , 0, dp);
    }
};