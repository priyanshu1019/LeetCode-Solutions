class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int [] leftMaxOf = new int[n];
        int [] rightMaxOf = new int[n];
        findLeftMax(leftMaxOf , height);
        findRightMax(rightMaxOf, height);
        int result = 0;
        for(int i = 0 ; i<n ; i++)
        {
            int rainTrapped = Math.min(leftMaxOf[i] , rightMaxOf[i])-height[i];
            result += rainTrapped;
        }
        return result;
    }
    static void findLeftMax(int[] leftMaxOf , int [] height)
    {
        int n = height.length;
        leftMaxOf[0]=height[0];
        for(int i = 1 ; i<n; i++)
        {
            leftMaxOf[i] = Math.max(leftMaxOf[i-1] , height[i]);
        }
    }
    static void findRightMax(int [] rightMaxOf, int[] height)
    {
        int n = height.length;
        rightMaxOf[n-1] = height[n-1];
        for(int i = n-2; i>=0 ; i--)
        {
            rightMaxOf[i] = Math.max(rightMaxOf[i+1] , height[i]);
        }
    }
}