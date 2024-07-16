class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();

        for(int i =0 ; i <  n ; ){
            int correct = nums[i]-1;
            if( nums[correct] != nums[i]){
                swap(nums[correct] , nums[i]);
            }else{
                i++;
            }
        }
        for(int i =0 ; i < n ; i++){
            if( i+1 != nums[i]){
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};