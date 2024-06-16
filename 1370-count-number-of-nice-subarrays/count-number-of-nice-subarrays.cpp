class Solution {
private:
    int helper(vector<int>&nums , int k)
    {
        int left = 0 , right = 0 , oddCount = 0 , count = 0 ;
        int n = nums.size();

        while( right < n )
        {
            if( nums[right] % 2 != 0)
            {
                oddCount ++;
            }
            while(oddCount > k)
            {
                if( nums[left] % 2 != 0)
                    oddCount --;
                left++;
            }

            count = count +(right - left + 1);
            right++;
        } 

        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return helper(nums , k) - helper(nums , k-1);
    }
};