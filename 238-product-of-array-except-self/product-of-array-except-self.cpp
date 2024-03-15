class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1); // Initialize left with size n and all elements as 1
        vector<int> right(n, 1); // Initialize right with size n and all elements as 1
        
        for(int i = 1 ; i < n ; i++ ) {
            left[i] = nums[i - 1] * left[i - 1];
        }
        
        for(int i = n - 2; i >= 0 ; i--) {
            right[i] = nums[i + 1] * right[i + 1];
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(left[i] * right[i]);
        }
        return ans;
    }
};
