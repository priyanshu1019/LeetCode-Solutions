class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        vector<int> dp(n , 1);
        vector<int> prev_idx(n , -1);
        sort(nums.begin()  , nums.end());
        int maxL = 1;
        int last_chosen_idx = 0;
        for(int i =0; i < n ; i++){
            for(int j = 0 ; j < i ; j++ ){
                if( nums[i] % nums[j] == 0){
                    if( dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }
                    if( dp[i] > maxL){
                        maxL = dp[i];
                        last_chosen_idx = i;
                    }
                }
            }
        }
        
        while(last_chosen_idx != -1){
            result.push_back(nums[last_chosen_idx]);
            last_chosen_idx = prev_idx[last_chosen_idx];
        }
        // reverse(result.begin() , result.end())
        return result;
    }
};