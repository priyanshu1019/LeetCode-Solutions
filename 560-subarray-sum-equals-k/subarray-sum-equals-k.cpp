class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int ,int> mp;

        int n= nums.size();

        int ans = 0;

        mp[0] = 1;
        int sum = 0;

        for(auto it:nums)
        {
            sum += it;
            int rem = sum - k;

            if( mp.find(rem) != mp.end())
            {
                ans = ans + (mp[rem]);
            }
            mp[sum]++;
        }

        return ans;
    }
};