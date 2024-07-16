class Solution {
public:
    vector<vector<int>> ans;
    void twoSum(vector<int>& nums , int start , int end , int target){
        int n = nums.size();
        while(start < end ){
            
            if( nums[start]+ nums[end] == target){
                while(start+1 < n and nums[start] == nums[start+1]){
                start++;
            }
            while(end-1 >=0 and nums[end-1] == nums[end]){
                end--;
            }
                ans.push_back({-target , nums[start] , nums[end]});
                start++;
                end--;
            }else if( nums[start] + nums[end] > target){
                end--;
            }else{
                start++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i =0 ; i <n ; i++){
            if( i > 0 and nums[i-1] == nums[i]){
                continue;
            }
            int target = -nums[i];

            twoSum(nums , i+1 , n-1 , target);
        }

        return ans;
    }
};