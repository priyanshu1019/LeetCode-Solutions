class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> result(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=0;
            }
            else{
                while(!st.empty() and temperatures[st.top()]<=temperatures[i]){
                    st.pop();
                }
                result[i]=st.empty()?0:st.top()-i;
            }
            st.push(i);
        }
        return result;

    }
};