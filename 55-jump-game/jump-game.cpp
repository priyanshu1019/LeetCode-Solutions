class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 || n == 1 ) return true; 
        //this is the point till what i can jump definitely 
        int maxInd = 0;

        for(int i = 0 ; i < n ;i++ ){
            if( i > maxInd) return false;
            maxInd = max(maxInd , i+nums[i]);
        }

        return true;

        return true;
    }
};