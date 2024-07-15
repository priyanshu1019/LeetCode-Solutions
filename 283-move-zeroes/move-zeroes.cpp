class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        int n = nums.size();

        for(int j = 0 ; j< n ; j++)
        {
            if(nums[j] != 0)
            {
                nums[++i] = nums[j];
            } 
        }
        if(i ==-1 || i == n) return ;  
        for(int j = i+1 ; j< n ; j++)
        {
            nums[j] = 0;
        }
    }
};