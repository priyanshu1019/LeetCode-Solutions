class Solution {
public:
    int check(vector<int>&weights , int cap , int days){
        int sum = 0;
        int d   = 1;
        
        for(int i = 0 ;i < weights.size() ; i++){
            if( sum + weights[i] <= cap){
                sum += weights[i];
            }else{
                sum = weights[i];
                d++;
            }
            if( d  > days)return -3;
        }
        return -1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1;
        int high = 0;
        for(int &weight:weights){
            low = max(weight , low);
            high+= weight;
        }

        while(low <= high){
            int capacity = low + (high - low)/2;
            int val      = check(weights , capacity , days);
            if( val == -3){
                low = capacity +1;
            }else{
                high= capacity-1;
            }
        }
        return low;
    }
};