class Solution {
private:
    long long helper(vector<int>& bloomDay , int mid , int m , int k )
    {
        long long count = 0;
        for(int i = 0 ; i< bloomDay.size() ; i++ )
        {
            if( bloomDay[i] <= mid)
            {
                count++;
                
            }else{
                count = 0;
            }
            if( count == k)
                {
                    m--;
                    count = 0;
                }
        if( m == 0) return 1;
        }
        return -3;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto it:bloomDay)
        {
            mini = min(mini , it);
            maxi = max(maxi , it);
        }
        int low = mini ;
        int high= maxi ;

        while( low <= high)
        {
            int mid = low + (high - low)/2;

            int days = helper(bloomDay , mid , m , k );

            if( days == -3 )
            {
                low = mid + 1;
            }else{
                high= mid - 1;
            }
        }

        return low == maxi + 1 ? -1 : low;
    }
};