class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        while( s[i] == ' ' and i < n)
        {
            i++;
        }
        int neg = 0;
        int pos = 0;
        if(s[i] == '+' ) pos++ , i++;
        if(s[i] == '-') neg++ , i++;
        double ans = 0;
        while( i<n and isdigit(s[i]))
        {
            ans = ans*10 + (s[i]-'0');
            i++;
        }
        if( neg > 0) ans = -ans;
        if(pos > 0 and neg > 0) ans = 0;
        if( ans<INT_MIN) ans = INT_MIN;;
        if( ans> INT_MAX) ans = INT_MAX;

        return ans;
    }
};