class Solution {
private:
    vector<int> getNSL(vector<int> &arr,int n){
        //we are storing index in res and stack
        stack<int> st;
        vector<int> res(n);
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                res[i]=-1;
            }else{

                while(!st.empty() and arr[st.top()]>=arr[i])
                    st.pop();

                res[i]=st.empty()?-1:st.top();

            }
            st.push(i);
        }
        return res;
    }
    vector<int> getNSR(vector<int> &arr,int n){
        //we are storing index in res and stack
        stack<int> st;
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]=n;
            }else{

                while(!st.empty() and arr[st.top()]>arr[i])
                    st.pop();

                res[i]=st.empty()?n:st.top();

            }
            st.push(i);
        }
        return res;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nsl=getNSL(arr,n);
        vector<int> nsr=getNSR(arr,n);

        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long ls=i-nsl[i];
            long long rs=nsr[i]-i;
            long long totalWays=ls*rs;// these many subarrays will have arr[i] as minimum
            long long totalSum=totalWays*arr[i];
            sum=(sum+totalSum)%mod;

        }

        return sum % mod;
    }
};