class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 ;
        int r = 0 ;
        int n = nums.size();
        int maxLen = 0;
        unordered_map<int , int> freq;
        while(r< n )
        {
            freq[nums[r]]++;

            while(freq[0] > k)
            {
                freq[nums[l]]--;
                if( freq[nums[l]] == 0)
                {
                    freq.erase(nums[l]);
                }
                l++;
            }

            maxLen = max(maxLen , r-l+1);
            r++;
        }

        return maxLen;
    }
};