class Solution {
public:
    vector<vector<int>> ans ;
    void twoSum(vector<int>&nums , int target , int low , int high){
        int n = nums.size();
        while(low < high){
            int sum = nums[low] + nums[high];
            if( sum > target){
                high--;
            }else if( sum < target){
                low++;
            }else{
                while(low+1 < n and nums[low+1] == nums[low]){
                    low++;
                }
                while(high - 1 >=0 and nums[high-1] == nums[high]){
                    high--;
                }
                ans.push_back({-target , nums[low ] , nums[high]});
                low++;
                high--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if( nums.size() < 3) return {};
        sort(nums.begin() , nums.end());

        int n = nums.size();

        for(int i =0 ; i< n ;i++){
            if( i > 0 and nums[i-1] == nums[i]){
                continue;
            }

            int target = -nums[i];

            twoSum(nums , target , i+1 , n-1 );

        }

        return ans;
    }
};