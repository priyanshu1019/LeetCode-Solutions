class Solution {
public:
    int check(vector<int>&nums , int mid , int n , int k){
        int count = 1;
        int sum  = 0;
        for(int i =0 ; i < n ; i++){
            if( sum + nums[i] <= mid){
                sum += nums[i];
            }else{
                count++;
                sum = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int n   = nums.size();
        int low = 0;
        int high= 0;
        for(int &x:nums){
            low = max(low , x);
            high= high+x;
        }

        while(low <= high){
            int mid = low + (high - low)/2;
            int val = check(nums , mid , n , k);
            if( val > k ){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};