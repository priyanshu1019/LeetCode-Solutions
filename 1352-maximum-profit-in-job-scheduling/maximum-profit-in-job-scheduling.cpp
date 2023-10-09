class Solution {
public:
    int n;
    int dp[50001];
    int getNextIndex(vector<vector<int>>&arr,int l,int currJobEnd ){
        //currJobInd is the target we need to find the first job with starttime greate or equal to end time of curr
        int r=n-1;
        int result=n+1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid][0]>=currJobEnd){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
    int helper(vector<vector<int>> &arr,int ind){
        if(ind>=arr.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        //get next job with start greater than current job end
        int nextInd=getNextIndex(arr,ind+1,arr[ind][1]);
        int take=arr[ind][2]+helper(arr,nextInd);
        int notTake=helper(arr,ind+1);
        return dp[ind]=max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=profit.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> arr(n,vector<int>(3,0));//s,e,p
        for(int i=0;i<n;i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }

        auto  myCmp=[&](auto &vec1, auto &vec2){
            return vec1[0]<=vec2[0];
        };

        //sort according to the start time 
        sort(begin(arr),end(arr),myCmp);
        return helper(arr,0);
    }
};