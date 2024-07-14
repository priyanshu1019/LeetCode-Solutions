class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0 , mid = 0 ;
        int n = nums.size();
        int high = n-1;

        while(mid <= high){
            if( nums[mid] == 2){
                swap(nums[mid] , nums[high--]);
            }else if( nums[mid] == 0){
                swap(nums[low++] , nums[mid++]);
            }else{
                mid++;
            }
        }
    }
};