class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(!st.empty() and asteroids[i]<0){
                
                while(!st.empty() and st.top()>0 and st.top()+asteroids[i]<0){
                    st.pop();
                }
                if(!st.empty() and abs(asteroids[i])==st.top()){
                    st.pop();
                    continue;
                }
                else if(!st.empty() and asteroids[i]+st.top()>0){
                    continue;
                }
            }
            st.push(asteroids[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};