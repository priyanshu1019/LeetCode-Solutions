class Solution {
public:
    int K;
    int solve(int ind , vector<int>&nums  , map<int,int>&mp){
        if( ind >= nums.size()){
            return 1;
        }
        int take = 0;
        if( !mp[nums[ind]+K] and !mp[nums[ind]-K]){
            mp[nums[ind]]++;
            take = solve(ind+1 , nums  , mp);
            mp[nums[ind]]--;
        }

        int notake = solve(ind +1, nums  , mp);

        return take + notake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        K = k;
        map<int,int> mp;
        return solve(0 , nums , mp)-1;
    }
};