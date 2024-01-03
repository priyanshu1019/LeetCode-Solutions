class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = high - (high-low) /2;
            int val = nums[mid];

            if( val == target ){
                return mid;
                            }
            else if( val >= nums[low] ){
                if( val > target and nums[low] <= target){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if( val  <=  target and target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }

        }

        return ans;
    }
};