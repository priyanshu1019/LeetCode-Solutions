class Solution {
private:
    int getFirst(vector<int> &nums , int target){
        int ans = -1;
        int n  = nums.size();
        int left = 0;
        int right = n-1;
        while(left <= right){
            int mid = left +(right-left)/2;
            if( nums[mid] > target){
                right = mid-1;
            }else if(nums[mid] == target){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
    int getLast(vector<int>&nums , int target){
        int ans = -1;
        int n  = nums.size();
        int left = 0;
        int right = n-1;
        while(left <= right){
            int mid = left +(right-left)/2;
            if( nums[mid] > target){
                right = mid-1;
            }else if(nums[mid] == target){
                ans = mid;
                left = mid+1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = getFirst(nums , target);
        int last  = getLast(nums , target);
        return {first , last};
    }
};