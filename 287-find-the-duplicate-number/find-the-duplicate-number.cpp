class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0 ; i < n ; ){
            int correct = nums[i] -1;
            if(nums[correct] != nums[i]){
                swap(nums[correct] , nums[i]);
            }else{
                i++;
            }
        }
        for(int i =0 ; i < n ; i++){
            if( nums[i] != (i+1)){
                return nums[i];
            }
        }

        return -1;
    }
};