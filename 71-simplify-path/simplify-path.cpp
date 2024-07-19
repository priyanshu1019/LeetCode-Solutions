class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        string token  = "";
        stack<string> st;
        stringstream ss(path);
        
        while(getline(ss , token , '/')){
            if( token == "" || token == "."){
                continue;
            }else if( token == ".."){
                if( !st.empty()) st.pop();
            }else{
                st.push(token);
            }
        }
        if( st.empty())return "/";
        while(!st.empty()){
            result ="/"+st.top()+ result;
            st.pop();
        }

        return result;
    }
};