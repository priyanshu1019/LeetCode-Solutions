class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1;
        int result = 0 ;
        int number = 0;
        int n      = s.size();

        for(int i =0 ; i < n ; i++){
            if( isdigit(s[i])){
                number = number*10 + (s[i]-'0');
            }else if( s[i] == '+'){
                result += (sign * number);
                sign = 1;
                number = 0;
            }else if( s[i] == '-'){
                result += (sign * number);
                sign = -1;
                number = 0;
            }else if( s[i] == '('){
                st.push(result);
                st.push(sign);
                sign = 1;
                number = 0;
                result = 0;
            }else if( s[i] == ')'){
                //closing brackets
                result += (number*sign);
                number = 0;

                int stack_sign = st.top();st.pop();
                int last_val   = st.top();st.pop();
                result = last_val + (stack_sign*result);
            }
        }

        //last wali value toh result me aaya hi nahi bhai
        result +=(sign*number);

        return result;
    }
};