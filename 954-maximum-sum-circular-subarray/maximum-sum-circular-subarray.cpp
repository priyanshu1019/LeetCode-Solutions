class Solution {
private:
    int maxSumKadane(vector<int> &nums)
    {
        int maxSum = nums[0];
        int n = nums.size();
        int currSum = nums[0];
        for(int i = 1 ; i<n ; i++)
        {
            currSum = max( currSum+nums[i] , nums[i]);
            maxSum  = max( maxSum , currSum);
        }
        return maxSum;
    }
    int minSumKadane(vector<int> &nums)
    {
        int minSum = nums[0];
        int n      = nums.size();
        int currSum = nums[0];
        for(int i = 1 ; i<n ; i++)
        {
            currSum = min( currSum+nums[i] , nums[i]);
            minSum  = min( minSum , currSum);
        }
        return minSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        //total sum 
        for(auto it:nums)
        {
            totalSum += it;
        }

        int maxSum         = maxSumKadane(nums);
        int minSum         = minSumKadane(nums);
        int circularMaxSum = totalSum - minSum;
        cout<<maxSum <<" "<<minSum <<" "<<circularMaxSum<<endl;
        if( circularMaxSum > maxSum )
        {
            return circularMaxSum == 0 ? maxSum : circularMaxSum ;
        }

        return maxSum;

    }
};