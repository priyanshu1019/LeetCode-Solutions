class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n   = nums.size();
        int low = 0;
        int high= n-1;
        int mid = 0;

        while( mid <= high)
        {
            if( nums[mid] == 2)
            {
                swap(nums[mid] , nums[high--]);
            }
            else if( nums[mid] == 0)
            {
                swap( nums[mid++] , nums[low++]);
            }else{
                mid++;
            }
        }
    }
};