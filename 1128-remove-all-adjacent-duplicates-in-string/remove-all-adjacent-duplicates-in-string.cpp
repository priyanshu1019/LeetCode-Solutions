class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.size();

        string str="";
        for(char ch:s){
            if( st.empty()){
                st.push(ch);
            }else{
                if( st.top() == ch){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }

        while(!st.empty()){
            str = st.top()+str;
            st.pop();
        }

        return str;
    }
};