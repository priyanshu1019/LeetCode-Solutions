class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        mp[0]++;

        for(int &num : nums){
            sum += num;
            int rem = sum % k ;

            if (rem < 0) rem = rem + k;

            if( mp.find(rem) != mp.end()){
                ans += mp[rem];
            }
            mp[rem]++;
        }
        
        return ans;
    
    }
};