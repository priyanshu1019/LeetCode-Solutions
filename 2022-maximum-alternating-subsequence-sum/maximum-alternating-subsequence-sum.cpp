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
        vector<vector<long long >> dp(nums.size()+1,vector<long long >(2,0));
        //base case
        int n=nums.size();
        dp[n][0]=0;
        dp[n][1]=0;
        for(int index=n-1;index>=0;index--){
            for(int j=0;j<=1;j++){
                //not_pick
                long long not_pick=dp[index+1][j];
                //pick
                long long pick=INT_MIN;
                if(j){
                    pick=nums[index]+dp[index+1][!j];
                }else if(j==false){
                    pick=-nums[index]+dp[index+1][!j];
                }

                dp[index][j]=max(not_pick,pick);
            }
        }
        return dp[0][1];
    }
};