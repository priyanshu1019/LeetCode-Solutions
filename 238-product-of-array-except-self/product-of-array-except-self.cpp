class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n  = nums.size();
        vector<int> answer(n);
        int count_zero = 0;
        int product_nonZero=1;
        int product = 1;

        for(auto it: nums)
        {
            product *= it;
            if( it == 0)
            {
                count_zero++;
            }else{
                product_nonZero *= it;
            }
        }

        if( product != 0)
        {
            for(int i = 0 ; i<n ;i++)
            {
                answer[i] =product/nums[i];
            }
        }
        else if( count_zero == 1){
            for(int i = 0; i<n ; i++)
            {
                if( nums[i] ==0)
                {
                    answer[i] = product_nonZero;
                }
            }
        }
        return answer;
    }
};