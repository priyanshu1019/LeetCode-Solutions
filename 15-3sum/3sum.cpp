class Solution {
public:
    vector<vector<int>> result;
    void twoSum(vector<int>& nums , int target , int l , int h)
    {
        int n = nums.size();
        while( l<h)
        {
            int sum = nums[l]+nums[h];
            if( sum > target )
            {
                h--;
            }else if( sum < target)
            {
                l++;
            }else{
                while( l<h and nums[l+1]== nums[l])l++;
                while( l<h and nums[h-1]==nums[h])h--;
                result.push_back({-target,nums[l],nums[h]});
                l++;
                h--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        if( n<3) return {};
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i<n-2;i++)
        {
            if(i>0 and nums[i]==nums[i-1])
            {
                continue;
            }
            int target = -nums[i];
            twoSum(nums , target,i+1 , n-1);
        }

        return result;
    }
};