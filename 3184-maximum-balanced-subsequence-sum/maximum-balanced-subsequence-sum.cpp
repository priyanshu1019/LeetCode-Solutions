class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        long long result = INT_MIN;
        map<int , long long > mp;
        
        for(int i =0 ; i < n ; i++){
            auto it = mp.upper_bound(nums[i] - i);
            //we need the element which is just smaller than nums[i] but upper bound gives just greater that nums[i]
            //but if we do it-- we will get just smaller than nums[i]
            long long sum = nums[i];
            if( it != mp.begin()){
                it--;
                sum += it->second;
            }
            mp[nums[i] - i] = max(mp[nums[i]-i] , sum);
            it = mp.upper_bound(nums[i]-i);
            
            while(it!= mp.end() and it->second <= sum){
                mp.erase(it++);
            }
            result = max(sum , result);
        }
        return result;
    }
};