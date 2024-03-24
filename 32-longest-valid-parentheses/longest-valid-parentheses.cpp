class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.length();

        int ans = 0;

        for(int i = 0 ; i<n ; i++)
        {
            char ch = s[i];
            if( ch=='(')
            {
                st.push(i);
            }else{
                if( !st.empty())
                {
                    st.pop();
                }
                if( !st.empty())
                {
                    ans = max(ans , i-st.top()); 
                }
                else{
                    st.push(i);//new invalid point;
                }
            }
        }
        return ans ;
    }
};