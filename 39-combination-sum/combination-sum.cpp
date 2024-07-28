class Solution {
public:
    vector<vector<int>> result;
    void solve(int ind , vector<int>& candidates ,vector<int>&curr, int target){
        if(target == 0){
            result.push_back(curr);
            return;
        }
        if( target < 0 || ind >= candidates.size()){
            return;
        }
        curr.push_back(candidates[ind]);
        solve(ind , candidates , curr , target-candidates[ind] );
        curr.pop_back();
        solve(ind +1 , candidates , curr , target );
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(0 , candidates , curr , target);
        return result;
    }
};