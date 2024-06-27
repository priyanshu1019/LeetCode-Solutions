class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        unordered_map<string , function<int (int , int)>> mp={
            {"+",[](int a, int b ){return a+b;}},
            {"-",[](int a, int b ){return a-b;}},
            {"*",[](int a, int b ){return a*b;}},
            {"/",[](int a, int b ){return a/b;}},
        };
        stack<int> st;
        for(int i =0 ; i < n ; i++){
            string token = tokens[i];
            if( token == "+" || token == "-" || token == "*" || token == "/"){
                int a= st.top();
                st.pop();
                int b= st.top();
                st.pop();

                int value = mp[token](b , a);
                st.push(value);
            }else{
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};