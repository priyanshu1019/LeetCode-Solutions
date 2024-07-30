class Solution {
public:
    int t[201][1001];
    int solve(int ind , vector<int>&nums , int target){
        if( target == 0){
            return 1;
        }
        if( target < 0 )return 0;
        if( ind >= nums.size()) return 0;
        if( t[ind][target]!= -1)return t[ind][target];
        int take = solve(0 , nums , target-nums[ind]);
        int notake = solve(ind+1 , nums , target);
        return t[ind][target] = take + notake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(t , -1 , sizeof(t));
        int ans = solve(0 , nums , target);
        return ans;    
    }
};