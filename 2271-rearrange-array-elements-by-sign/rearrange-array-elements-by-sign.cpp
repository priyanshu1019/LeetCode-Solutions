class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int neg = 1;
        int pos = 0;
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0 ; i<n ; i++)
        {
            if( nums[i] < 0)
            {
                ans[neg] = nums[i];
                neg += 2;
            }
            else {
                ans[pos] = nums[i];
                pos +=2;
            }
        }
        return ans;
    }
};