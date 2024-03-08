class Solution {
public:
    int findKthPositive(vector<int>& vec, int k) {
            int low = 0;
            int n = vec.size();
            int high = n -1;
            while( low <= high)
            {
                int mid = low + (high - low)/2;
                int missing = vec[mid] - (mid + 1);

                if( missing >= k)
                {
                    high = mid -1;
                }else{
                    low = mid + 1;
                }
            }
            return k + high + 1;
    }
};