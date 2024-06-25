class Solution {
public:
    vector<int> getNsl(vector<int> &arr){
        int n = arr.size();
        vector<int> nsl(n);
        stack<int> st;

        for(int i =0 ; i < n; i++){
            if( st.empty()){
                nsl[i] = -1;
            }else{
                while(!st.empty() and arr[st.top()] >= arr[i]){
                    st.pop();
                }
                nsl[i] = st.empty()?-1:st.top();
            }
            st.push(i);
        }
        return nsl;
    }
    vector<int> getNsr(vector<int> &arr){
        int n = arr.size();
        vector<int> nsr(n);
        stack<int> st;

        for(int i =n-1 ; i >=0; i--){
            if( st.empty()){
                nsr[i] = n;
            }else{
                while(!st.empty() and arr[st.top()] > arr[i]){
                    st.pop();
                }
                nsr[i] = st.empty()?n:st.top();
            }
            st.push(i);
        }
        return nsr;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl = getNsl(arr);
        vector<int> nsr = getNsr(arr);

        int sum = 0;
        int mod = 1e9+7;

        for(int i =0 ; i < n ; i++){
            long long ls = i-nsl[i];
            long long rs = nsr[i] - i;

            long long ways = ls * rs;
            long long totalSum = ways*arr[i];
            sum = ( sum + totalSum ) % mod;
        }

        return sum;
    }
};