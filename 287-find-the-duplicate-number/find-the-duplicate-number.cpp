class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while( i<n )
        {
            int correctPos = nums[i]-1;
            if( nums[correctPos] != nums[i])
            {
                swap(nums[correctPos] , nums[i]);
            }else{
                i++;
            }
        }
        for(int i = 0 ; i<n ; i++)
        {
            if( nums[i] -1 != i)
            {
                return nums[i];
            }
        }
        return -1;
    }
};