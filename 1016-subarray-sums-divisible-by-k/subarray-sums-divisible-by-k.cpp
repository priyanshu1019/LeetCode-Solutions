class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] =1;

        int result = 0;
        int sum    = 0;
        for(auto &num:nums)
        {
            sum += num;
            int rem = sum % k;

            if( rem < 0)
            {
                rem += k;
            }
            if( mp.find(rem) != mp.end())
            {
                result += mp[rem];
            }
            mp[rem]++;
        }
        return result;

    }
};