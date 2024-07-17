class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for( char c:s)
        {
            if(c == '{'||c == '('||c =='[' ){
                st.push(c);
            }else{
                if( st.empty() || 
                (c == ')' and st.top() != '(') || 
                (c == '}' and st.top() != '{') ||
                (c == ']' and st.top() != '[')){
                    return false;
                }
                st.pop();
            }
            
        }

        return st.empty();
        
    }
};