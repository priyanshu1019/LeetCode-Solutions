class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int number=0;
        int result=0;
        int sign=1;
        stack<int> st;
        for(int i=0;i<n;i++ ){
            if(isdigit(s[i])){
                number=number*10+(s[i]-'0');
            }else if(s[i]=='+'){

                result+=(sign*number);
                number=0;
                sign=1;

            }else if(s[i]=='-'){
                result+=(sign*number);
                number=0;
                sign= -1;
            }else if(s[i]=='('){

                st.push(result);
                st.push(sign);
                result=0;
                number=0;
                sign=1;
            }else if(s[i]==')'){
               result += sign*number;
                number = 0;
                int top = st.top(); st.pop();
                result *= top;
                top = st.top(); st.pop();
                result += top;
            }
        }
        result+=sign*number;
        return result;
    }
};