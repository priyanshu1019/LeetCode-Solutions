class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentMinimum  = prices[0];
        int n               = prices.size();
        int totalProfit     = 0;
        for(int day = 1 ; day < n ; day++ ){
            if( prices[day] > currentMinimum ){
                totalProfit += ( prices[day] - currentMinimum);
                currentMinimum = prices[day];
            }else{
                currentMinimum = prices[day];
            }
        }

        return totalProfit;
    }
};