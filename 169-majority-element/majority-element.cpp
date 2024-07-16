class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count     = 0;
        int n         = nums.size();

        for(int i =0 ; i < n ;i++){
            if( count == 0 ){
                candidate = i;
                count=1;
            }else{
                if( nums[i] == nums[candidate]){
                    count++;
                }else{
                    count--;
                }
            }
        }

        return nums[candidate];
    }
};