class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = INT_MIN;
        int currCount = 0 ;
        for(auto it: nums)
        {
            if( it == 0 )
            {
                currCount = 0;
            }
            else{
                currCount++;
                maxCount = max(maxCount , currCount);
            }
        }
        return maxCount == INT_MIN? 0:maxCount;
    }
};