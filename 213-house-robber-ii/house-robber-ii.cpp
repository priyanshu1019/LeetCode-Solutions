class Solution {
private:
    int helper(vector<int> &nums)
    {
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
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> temp1,temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }if(i!=(nums.size()-1)){
                temp2.push_back(nums[i]);
            }
        }
        return max(helper(temp1),helper(temp2));
    }
};