class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ind = -1;
        int n   = nums.size();
        for(int i = 0 ; i<n; i++)
        {
            if( nums[i]!=0)
            {
                swap(nums[++ind],nums[i]);
            }
        }
        // if(nums[n-1]!=0)
        // {
        //     swap(nums[++ind] ,nums[n-1]);
        // }
    }
};