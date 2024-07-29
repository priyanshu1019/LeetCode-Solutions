class Solution {
public:
    vector<vector<int>> result;
    
    void solve(int ind, vector<int>& nums) {
        if (ind >= nums.size()) {
            result.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for (int i = ind; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end()) {
                continue; // skip duplicates
            }
            seen.insert(nums[i]);
            swap(nums[i], nums[ind]);
            solve(ind + 1, nums);
            swap(nums[i], nums[ind]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums);
        return result;
    }
};
