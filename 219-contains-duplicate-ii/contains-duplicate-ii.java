class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer , Integer> mp = new HashMap<>();
        int n = nums.length;
        for(int i = 0 ; i<n ; i++ )
        {
            if( !mp.containsKey(nums[i]))
            {
                mp.put(nums[i],i);
            }
            else {
                if( Math.abs(mp.get(nums[i])-i) <= k)
                {
                    return true;
                }else{
                    mp.put(nums[i],i);
                }
            }
        }
        return false;
    }
}