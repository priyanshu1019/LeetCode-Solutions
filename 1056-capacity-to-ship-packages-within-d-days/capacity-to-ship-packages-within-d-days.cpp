class Solution {
private:
    int check(vector<int> &weights , int limit , int d)
{
    long long sum = 0;
    int day = 1;
    for(int i = 0 ; i< weights.size() ;i++)
    {
        if( sum + weights[i] > limit)
        {
            day++;
            sum = weights[i];
        }else{
            sum += weights[i];
        }
    }
    return day;
}
public:
    int shipWithinDays(vector<int>& weights, int d) {
        int n    = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while( low <= high )
        {
            int mid = low + (high - low) / 2;
            long long days = check( weights , mid , d );
            if(days <= d)
            {
                high = mid -1;
            }else{
                low = mid + 1;
            }

        }
        return low;
    }
};