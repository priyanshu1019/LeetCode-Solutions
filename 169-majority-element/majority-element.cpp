class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = -1;

        int count = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            if( count == 0){
                candidate = i;
                count++;
            }
            else {
                if( nums[i] == nums[candidate]){
                    count++;
                }else{
                    count--;
                }
            }
        }

        count = 0;
        for(int i =0 ; i<n ; i++)
        {
            if(nums[i] == nums[candidate]){
                count++;
            }
        }
        return count > (n/2) ? nums[candidate] : -1;
    }
};