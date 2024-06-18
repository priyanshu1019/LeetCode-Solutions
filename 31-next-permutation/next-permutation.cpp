class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       
        int n = nums.size();
        int ind = -1;

        //find the break point 

        for(int i = n-2 ; i>= 0 ; i--)
        {
            if( nums[i+1] > nums[i])
            {
                ind = i;
                break;
            }
        }

        if( ind == -1){
            return reverse(nums.begin() , nums.end());
        }

        //find just greater and swap 
        for(int i = n-1 ; i> ind ; i--)
        {
            if( nums[i] > nums[ind])
            {
                swap(nums[i] , nums[ind]);
                break;
            }
        }

        //reverse elements after break point
        return reverse(nums.begin() + ind + 1 , nums.end());
        

    }
};