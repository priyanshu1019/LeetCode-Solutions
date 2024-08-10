class Solution {
public:
    int check(vector<int>&piles , int k , int h){
        int hours = 0;
        for(int i = 0 ; i < piles.size() ; i++ ){
            hours += ceil((double)piles[i]/k);
            if( hours > h)return -3;
        }
        return -1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        for(int x:piles){
            high = max(high , x);
        }
        int low = 1;

        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            int val = check(piles , mid  , h);
            if( val == -3){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};