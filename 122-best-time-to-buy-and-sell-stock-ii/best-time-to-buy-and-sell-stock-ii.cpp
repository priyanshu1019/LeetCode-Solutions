class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dipPoint = INT_MAX;
        int profit   = 0;

        for(int i =0 ; i < n ; i++ ){
            if( i == 0 || prices[i] < prices[i-1]){
                dipPoint = prices[i];
                continue;
            }else{
                profit  = profit + (prices[i] - dipPoint);
                dipPoint = prices[i];
            }
        }

        return profit;

    }
};