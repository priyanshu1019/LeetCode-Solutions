class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 ;
        int high = n -1;

        int ind = -1;
        while( low <= high )
        {
            int mid = low + (high - low ) / 2;
            if( nums[mid] >= target )
            {
                ind = mid ;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        if( ind == -1 )
        {
            if( low == n) return n;
            if( high == 0) return 0;
        }
        return ind ;
    }
};