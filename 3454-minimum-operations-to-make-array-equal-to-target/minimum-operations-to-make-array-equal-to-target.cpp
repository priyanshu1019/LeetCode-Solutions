class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long result = 0;
        int n = nums.size();
        vector<int> diff(n);

        for(int i = 0 ;i < n ; i++){
            diff[i] = target[i] - nums[i];
        }  
        int prev = 0;
        int curr = 0;
        for(int i =0 ; i < n; i++){
            curr = diff[i];
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