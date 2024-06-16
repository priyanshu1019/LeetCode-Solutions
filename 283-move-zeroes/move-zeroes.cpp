class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        int n = nums.size();

        for(int j = 0 ; j< n ; j++)
        {
            if( j == 0 and nums[j] != 0)
            {
                i++;
            }
            if(j != 0 and nums[j] != 0)
            {
                nums[++i] = nums[j];
            } 
        }
        cout<<i<<endl;
        if(i ==-1 || i == n) return ;  
        for(int j = i+1 ; j< n ; j++)
        {
            nums[j] = 0;
        }
    }
};