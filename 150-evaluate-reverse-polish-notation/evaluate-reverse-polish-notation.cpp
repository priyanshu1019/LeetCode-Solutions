class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        set<string> s;
        s.insert("+");
        s.insert("-");
        s.insert("/");
        s.insert("*");
        for(int i=0;i<tokens.size();i++){
            string curr=tokens[i];
            if(s.find(curr)!=s.end() ){
                int b=stoi(st.top());
                st.pop();
                int a=stoi(st.top());
                st.pop();
                if(curr=="+"){
                    st.push(to_string(a+b));
                }else if(curr=="-"){
                    st.push(to_string(a-b));
                }else if(curr=="*"){
                    st.push(to_string(a*b));
                }else{
                    st.push(to_string(a/b));
                }
            }else{
                st.push(curr);
            }
        }
        int result=stoi(st.top());
        return result;
    }
};