class Solution {
public:
    set<vector<int>>st;
    void solve(int ind , vector<int>&nums , vector<int>&curr){
        if( ind >= nums.size()){
            st.insert(curr);
            return;
        }
        curr.push_back(nums[ind]);
        solve(ind+1 , nums, curr);
        curr.pop_back();
        solve(ind+1 , nums , curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin() , nums.end());
        vector<int> curr;
        solve(0 , nums,curr);
        for(auto it:st){
            result.push_back(it);
        }
        return result;
    }
};