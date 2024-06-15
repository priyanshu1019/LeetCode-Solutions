class Solution {
private:
    int helper(vector<int>&nums , int goal)
    {
        if( goal < 0 ) return 0;
        int sum = 0 ,  left = 0 , right = 0 , count = 0 ;
        int  n = nums.size();
        // cout<<right<<endl;
        while(right < n )
        {
            sum += nums[right];

            while(sum > goal)
            {
                sum = sum -  nums[left];
                left++;
            }
            count = count + (right - left +1 );
            right++;

        }

        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if( goal < 0 ) return 0;

        return helper(nums , goal) - helper(nums , goal-1);
    }
};