class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<long long >>dp(n +1 , vector<long long >(2 , 0));

        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int index = n-1 ; index >=0 ; index--){
            for(int j = 0 ; j <=1 ; j++){
                long long ignore = dp[index+1][j];
                long long pick   = INT_MIN;

                if( j ){
                    pick   = nums[index]+dp[index+1][!j];
                }else if( j == 0){
                    pick   = -nums[index]+ dp[index+1][!j];
                }
                dp[index][j] = max(ignore , pick);
            }
        }
        return dp[0][1];
    }
};