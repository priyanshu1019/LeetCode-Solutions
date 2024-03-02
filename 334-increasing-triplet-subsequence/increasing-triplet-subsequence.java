class Solution {
    public boolean increasingTriplet(int[] nums) {
        int first_small = Integer.MAX_VALUE;
        int second_small = Integer.MAX_VALUE;
        for(int i = 0 ; i<nums.length; i++)
        {
            if( nums[i] <= first_small)
            {
                first_small = nums[i];
            }else if( nums[i] <= second_small)
            {
                second_small = nums[i];
            }else{
                return true;
            }
        }
        return false;
    }
}