class Solution {
public:
    string simplifyPath(string path) {
        string token="";
        stringstream ss(path);
        stack<string> st;
        while(getline(ss,token,'/')){
            if(token==""|| token=="."){
                continue;
            }
                if(token!=".."){
                    //some folder name
                    st.push(token);
                }else if(!st.empty()){
                    //.. so pop
                    st.pop();
                }
            
        }
        string result="";
        if(st.empty()){
            return "/";
        }
        while(!st.empty()){
            result="/"+st.top()+result;
            st.pop();
        }
        return result;
    }
};