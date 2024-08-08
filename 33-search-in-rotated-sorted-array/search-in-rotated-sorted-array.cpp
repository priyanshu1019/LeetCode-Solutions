class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if( nums[mid] == target) return mid;
            //mid in left part
            else if( nums[mid] >= nums[low]  ){
                //target in left part or no
                if( target >= nums[low] and target<= nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            //mid in right part
            else{
                if( target >= nums[mid] and target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};