class Solution {
public:
    int ans = INT_MAX;
    void helper(vector<int>&cookies , int ind , vector<int>&arr ){
        if(ind == cookies.size()){
            //do something here
            int maxi = INT_MIN;
            for(auto &it:arr){
                maxi = max(it, maxi);
            }
            ans = min(ans , maxi);
            return ;
        }
        for(int i = 0 ; i < arr.size() ; i++){
            int temp = arr[i];
            arr[i]  += cookies[ind];

            helper(cookies , ind+1 , arr);
            arr[i]   = temp;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> arr(k,0);
        helper(cookies , 0 , arr );
        return ans;
    }
};