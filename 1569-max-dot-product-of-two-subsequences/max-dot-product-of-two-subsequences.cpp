class Solution {
private:
    int n,m;
    int dp[501][501];
    int helper(vector<int> &nums1,vector<int> &nums2,int i,int j){
        if(i==n||j==m){
            return -100000000;
        }
        if(dp[i][j]!=-1e9){
            return dp[i][j];
        }
        int val=nums1[i]*nums2[j];
        //take both of them
        int take_i_j=val+helper(nums1,nums2,i+1,j+1);
        //take either
        int take_i=helper(nums1,nums2,i,j+1);
        int take_j=helper(nums1,nums2,i+1,j);

        return dp[i][j]=max({val,take_i_j,take_i,take_j});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                dp[i][j]=-1e9;
            }
        }
        n=nums1.size();
        m=nums2.size();
        return helper(nums1,nums2,0,0);
    }
};