class Solution {
public: 
    long long helper(vector<int>&nums , int ind , bool even , vector<vector<long long>>&dp){
        if( ind == nums.size()) return 0;
        if( dp[ind][even]!= -1) return dp[ind][even];
        long long notPick = helper(nums , ind + 1, even , dp );
        long long  pick    = INT_MIN;

        if( even ){
            pick    = nums[ind] + helper(nums , ind+1 , false, dp);
        }else{
            pick    = -nums[ind]+ helper(nums , ind+1 , true , dp);
        }

        return dp[ind][even]=max(pick , notPick);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long >> dp(nums.size()+1 , vector<long long >(2 , -1));
        return helper(nums , 0 , true , dp);
    }
};