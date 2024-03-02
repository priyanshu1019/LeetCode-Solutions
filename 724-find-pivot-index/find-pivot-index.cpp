class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ind      =-1;
        int totalSum = 0;
        int n        = nums.size();
        for(auto &num : nums)
        {
            totalSum += num;
        }
        int leftSum = 0;
        int rightSum = totalSum;
        for(int i = 0 ; i < n ; i++)
        {
            rightSum -= nums[i];
            if( leftSum == rightSum )
            {
                ind = i;
                return ind;
            }
            leftSum += nums[i];
        }

        return ind;

    }
};