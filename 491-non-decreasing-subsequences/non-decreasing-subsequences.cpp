class Solution {
public:
    set<vector<int>>st;
    void helper(vector<int>&nums , vector<int>&curr , int ind , int prev){

        if( ind >= nums.size()){
            if(curr.size() >=2 )
                st.insert(curr);
            return;
        }
        if( prev == -1 || nums[ind] >= nums[prev]){
            curr.push_back(nums[ind]);
            helper(nums , curr , ind+1 , ind);
            curr.pop_back();
        }
        helper(nums , curr , ind+1 , prev);
        

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        helper(nums , curr , 0 , -1);
        vector<vector<int>> result;
        for(auto it:st){
            result.push_back(it);
        }
        return result;
    }
};