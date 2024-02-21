class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = -1;
        int n   = nums.size();
        for(int i = 0 ;i<=n-2 ; i++)
        {
            if( nums[i+1] != nums[i] )
            {
                nums[++ind] = nums[i];
            }
        }
        nums[++ind] = nums[n-1];
        return ind+1;
    }
};