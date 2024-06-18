class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);
        int pos = 0 ;
        int neg = 1;
        //traverse and get pos values and neg values
        for(auto it:nums){
            if( it > 0){
                ans[pos] = it;
                pos = pos + 2;
            }else{
                ans[neg] = it;
                neg = neg+2;
            }
        }

        return ans;

    }
};