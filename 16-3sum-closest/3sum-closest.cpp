class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n         = nums.size();
        int curr_diff = INT_MAX;
        int result = 0;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i<n ; i++)
        {
            int firstVal = nums[i];
            int l = i+1;
            int h = n-1;
            while( l < h )
            {
                int sum = nums[l]+nums[h];
                int total = sum + firstVal;
                if(total == target)
                {
                    return target;
                }else if( total < target)
                {
                    int diff = target-total;
                    if( diff < curr_diff) {
                        result = total;
                        curr_diff = diff;
                    }
                    l++;
                }else{
                    int diff = total-target;
                    if( diff < curr_diff) {
                        result = total;
                        curr_diff = diff;
                    }
                    h--;
                }
            }
        }
        return result;
    }
};