class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; )
        {
            int correct = nums[i];
            if( nums[i] <n and nums[i] != nums[correct]  )
            {
                swap(nums[i] , nums[correct]);
            }else{
                i++;
            }
        }
        for(int i = 0 ; i<n ; i++)
        {
            cout<<nums[i] <<" ";
            if( nums[i] !=i)
            {
                return i;
            }
        }
        return n;
    }
};