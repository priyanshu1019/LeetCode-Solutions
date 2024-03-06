class Solution {
private:
int getFirst(vector<int>& arr , int n , int target)
{
    int low = 0;
    int high= n - 1;
    int ind = -1;
    
    while( low <= high )
    {
        int mid = low + (high - low)/2;
        if( arr[mid] == target)
        {
            ind = mid ;
            high= mid - 1;
        }else if( arr[mid] > target )
        {
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ind ;

}
int getLast(vector<int> &arr , int n , int target)
{
    int low = 0;
    int high= n -1;
    int ind = -1;

    while(low <= high )
    {
        int mid = low + (high - low)/2;
        if( arr[mid] == target)
        {
            ind = mid;
            low = mid + 1;
        }else if( arr[mid] > target)
        {
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ind;
}
public:
    vector<int> searchRange(vector<int>& arr, int k) {
        int n     = arr.size();
        int first = getFirst(arr, n, k);
        int last  = getLast(arr, n, k);

        return {first , last};
    }
};