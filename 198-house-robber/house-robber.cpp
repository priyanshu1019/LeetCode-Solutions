class Solution {
private:
    int helper(int ind,vector<int> &nums,vector<int> &dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick=nums[ind]+helper(ind-2,nums,dp);
        int non_pick=helper(ind-1,nums,dp);
        return dp[ind]=max(pick,non_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n+1,-1);
        // dp[0]=nums[0];
        int prev1=0;
        int prev2=0;
        for(int i=0;i<n;i++){
            int pick=nums[i];
            pick+=prev2;
            int non_pick=prev1;
            prev2=prev1;
            prev1=max(pick,non_pick);
        }
        return prev1;
    }
};