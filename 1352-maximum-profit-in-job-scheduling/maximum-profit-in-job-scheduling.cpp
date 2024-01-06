class Solution {
public:
    int n;
    int dp[50001];
    int getNextIndex(vector<vector<int>> &arr , int s , int currEnd)
    {
        int e = n-1;
        int result = n+1;
        while( s<= e )
        {
            int mid = e - (e - s)/2;
            if( arr[mid][0] >= currEnd) 
            {
                result = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return result;
    }
    int helper(vector<vector<int>> &arr , int index )
    {
        if( index >= n ) return 0;
        if(dp[index] != -1) return dp[index];
        int nextInd = getNextIndex(arr , index+1 , arr[index][1]);
        int take = arr[index][2] + helper(arr , nextInd) ;
        int notTake = 0 + helper(arr , index+1);

        return dp[index] = max(take , notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
       n = profit.size();
       memset(dp , -1 , sizeof(dp));
       vector<vector<int>> arr(n , vector<int>(3 , 0));

       for(int i = 0 ; i<n ; i++)
       {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
       }

       auto myCmp = [&] (auto &vec1 , auto &vec2)
       {
           return vec1[0] <= vec2[0];
       };

       //sort acc to start time 
       sort(arr.begin() , arr.end() , myCmp);
       return helper(arr,0);

    }
};