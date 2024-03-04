class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        int n = nums.length;
        int m = queries.length;
        int[] answer = new int[m];
        //sort
        Arrays.sort(nums);
        //cummSum
        for(int i =1 ; i< n ; i++)
        {
            nums[i] += nums[i-1];
        }
        for(int i = 0 ; i< m ; i++)
        {
            int count = binarySearch(nums , queries[i] );
            answer[i] = count;
        }

        return answer;

    }
    private static int binarySearch(int[] sumTill , int target)
    {
        int n = sumTill.length;
        int l = 0;
        int h = n-1;
        int ind = -1;

        while( l<=h)
        {
            int mid = l+(h-l)/2;
            if( sumTill[mid] <= target)
            {
                ind = mid;
                l   = mid + 1;
            }else{
                h   = mid - 1;
            }
        }
        
        return ind + 1;
    }
}