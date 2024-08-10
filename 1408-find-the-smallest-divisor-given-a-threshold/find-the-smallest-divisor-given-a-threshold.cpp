class Solution {
public:
    int check(vector<int>&nums ,int mid ,  int threshold){
        int sum = 0;
        for(int &x:nums){
            sum += ceil((double)x/mid);
            if( sum >threshold)return -3;
        }
        return -1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high= 1;
        for(int &i:nums){
            high = max(high , i);
        }

        while(low <= high){
            int mid = low + (high - low)/2;
            int val = check(nums , mid , threshold);
            if( val == -3){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};