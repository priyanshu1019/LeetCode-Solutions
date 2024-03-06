class Solution {
public:
    int search(vector<int>& arr, int k) {
        int n   = arr.size();
        int low = 0 ;
        int high= n-1;
        
        while( low <= high)
        {
            int mid = low + (high - low)/2;
            if( arr[mid] == k)
            {
                return mid;
            }else if( arr[low] <= arr[mid])
            {
                if( k>= arr[low] and k<= arr[mid])
                {
                    high = mid;
                }else{
                    low = mid + 1;
                }
            }else{
                if(k>= arr[mid] and k <= arr[high])
                {
                    low = mid;
                }else{
                    high= mid - 1;
                }
            }
        }
        return -1;
    }
};