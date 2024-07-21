class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long result = 0;
        int n = nums.size();
        int prev = 0;
        int curr = 0;
        for(int i =0 ; i < n; i++){
            curr = target[i]-nums[i];
            //sign change
            if((curr > 0 and prev < 0)||( curr < 0 and prev > 0)){
                result += abs(curr);
            }else if( abs(curr) > abs(prev) ){
                result += abs(curr-prev);
            }
            prev = curr;
        }
        return result;
    }
};