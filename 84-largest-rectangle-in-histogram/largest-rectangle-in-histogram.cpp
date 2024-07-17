class Solution {
    vector<int> getNsl(vector<int>& heights ){
        int n = heights.size();
        vector<int> nsl(n);
        stack<int> st;

        for(int i =0 ; i < n ; i++){
            if(st.empty()){
                nsl[i] = -1;
            }else{
                while(!st.empty() and heights[st.top()] >= heights[i]){
                    st.pop();
                }

                nsl[i] = st.empty()? -1:st.top();
            }
            st.push(i);
        }
        return nsl;
    }
    vector<int> getNsr(vector<int>& heights ){
        int n = heights.size();
        vector<int> nsr(n);
        stack<int> st;

        for(int i =n-1 ; i >=0 ; i--){
            if(st.empty()){
                nsr[i] = n;
            }else{
                while(!st.empty() and heights[st.top()] >= heights[i]){
                    st.pop();
                }

                nsr[i] = st.empty()? n:st.top();
            }
            st.push(i);
        }
        return nsr;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl = getNsl(heights);
        vector<int> nsr = getNsr(heights);

        int ans = INT_MIN;
        int n   = heights.size();
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , heights[i]*(nsr[i]-nsl[i]-1));
            cout<<nsr[i]<<" "<<nsl[i]<<" "<<endl;
        }

        return ans;
    }
};