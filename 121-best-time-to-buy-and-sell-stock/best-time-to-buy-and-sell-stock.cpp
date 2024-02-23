class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = INT_MIN;
        int n = prices.size();
        int lowerCkt = prices[0];
        for(int i = 1 ; i <n ; i++)
        {
            maxP = max(maxP , prices[i] - lowerCkt);
            lowerCkt = min(lowerCkt , prices[i]);
        }
        return maxP>0? maxP : 0;
    }
};