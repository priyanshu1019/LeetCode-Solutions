class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long  totalSum = 0;
        int n = nums.size();
        for(auto it:nums)
        {
            totalSum += it;
        }
        int ind = 0;
        int minDiff = INT_MAX;
        long long  leftSum = 0;
        for(int i = 0 ; i< n ; i++)
        {
            leftSum += nums[i];
            int avg1 = leftSum / (i + 1);
            long long  rightSum = totalSum - leftSum;
            int avg2 = i<n-1 ? (rightSum / (n - i - 1)) : 0;
            int diff = abs(avg1 - avg2);
            if( diff < minDiff || (diff == minDiff && i < ind))
            {
                minDiff = diff;
                ind = i;
            }
        }
        return ind;
    }
};