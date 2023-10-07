class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string,function<int (int,int)> > mp={
            {"+" ,[](int a,int b){ return a+b; }},
            {"-" ,[](int a,int b){ return a-b;}},
            {"*" ,[](int a,int b){ return a*b;}},
            {"/" ,[](int a,int b){ return a/b;}},
        };
        for(int i=0;i<tokens.size();i++){
            string curr=tokens[i];
            if(curr=="+" || curr=="-"|| curr=="*" || curr=="/"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                int value=mp[curr](a,b);
                st.push(value);
            }else{
                st.push(stoi(curr));
            }
        }
        int result=st.top();
        return result;
    }
};