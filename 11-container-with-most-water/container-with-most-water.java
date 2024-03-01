class Solution {
    public int maxArea(int[] height) {
        
        int n     = height.length;
        int left  = 0 ;
        int right = n-1;
        int result = Integer.MIN_VALUE;
        while( left<right )
        {
            int Width   = right - left;
            int Length    = Math.min(height[left] , height[right]);
            int currArea = Length * Width;
            result       = Math.max(result , currArea );
            if( height[right] > height[left] )
            {
                left++;
            }else{
                right--;
            }
        }
        return result;
    }
}