class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        for(auto a:asteroids){
            while(!st.empty() and a<0 and st.top()>0){
                int sum=a+st.top();
                if(sum<0){
                    st.pop();
                }
                else if(sum==0){
                    st.pop();
                    a=0;//so that loop break;
                }else{
                    a=0;
                }
            }
            if(a!=0){
                st.push(a);
            }
        }
        int len=st.size();
        vector<int> ans(len);
        int i=len-1;
        while(!st.empty()){
            ans[i]=st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};