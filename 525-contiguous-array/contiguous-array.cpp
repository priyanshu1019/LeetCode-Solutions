class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        mp[0] = -1;
        int currSum = 0;
        int ans = 0;

        for(int ind = 0 ; ind < n ; ind++ )
        {
            currSum += nums[ind] == 0 ? -1 : 1 ;

            if( mp.find(currSum) != mp.end() )
            {
                int len = ind - mp[currSum];
                ans = max(len , ans);
            }else{
                mp[currSum] = ind;
            }
        }
        return ans;
    }
};