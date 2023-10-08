class Solution {
private:
    long long helper(int index, vector<int> &nums,bool even,vector<vector<long long >> &dp){
        //base case
        if(index==nums.size()){
            return 0;
        }
        if(dp[index][even]!=-1){
            return dp[index][even];
        }
        //not_pick
        long long not_pick=helper(index+1,nums,even,dp);
        //pick
        long long pick=INT_MIN;
        if(even){
            pick=nums[index]+helper(index+1,nums,false,dp);
        }else if(even==false){
            pick=-nums[index]+helper(index+1,nums,true,dp);
        }

        return dp[index][even]=max(not_pick,pick);
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long >> dp(nums.size()+1,vector<long long >(2,-1));
        return helper(0,nums,true,dp);
    }
};