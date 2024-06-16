class Solution {
private:
    int helper(vector<int>&nums , int k)
{
    int n = nums.size();
    int left = 0 , right = 0 , maxLen = 0;

    unordered_map<int , int> freq;

    while(right < n )
    {
        freq[nums[right]] ++;

        while(freq.size()>k)
        {
            freq[nums[left]]--;
            if( freq[nums[left]] == 0 ) freq.erase(nums[left]);

            left++;
        }

        if( freq.size() <= k ) maxLen = maxLen + (right - left + 1);

        right++;
    }

    return maxLen;
}
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums , k ) - helper(nums , k-1);
    }
};