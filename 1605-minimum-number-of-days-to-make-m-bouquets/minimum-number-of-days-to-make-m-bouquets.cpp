class Solution {
public:
    int check(vector<int>& bloomDay , int m , int k , int days){
        int flow = 0;
        int bouquets = 0;
        for(int i =0 ; i < bloomDay.size(); i++){
            if( bloomDay[i] <= days){
                flow++;
            }else{
                flow = 0;
            }
            if( flow == k){
                flow = 0;
                bouquets++;
            }
        }
        return bouquets >= m ?  -1:-3;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if( m > bloomDay.size()/k)return -1;
        int low = 0;
        int high= 0;

        for(int x:bloomDay){
            low = min(low, x);
            high= max(high , x);
        }

        while( low <= high){
            int mid = low+(high - low)/2;
            int val = check(bloomDay , m , k , mid);
            if( val == -3){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};