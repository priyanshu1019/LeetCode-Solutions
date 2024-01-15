class Solution {
public:
    bool helper(int i , int j , string &s , string &p )
    {
        if( i>=s.size() and j >= p.size() ) return true;
        if( j>= p.size()) return false;

        bool match = i < s.size() and (s[i] == p[j] or p[j] == '.');

        if( j+1 < p.size() and p[j+1] == '*')
        {
            return helper(i  , j+ 2, s , p) or (match and helper(i+1 , j , s , p));
        }
        if(match)
        {
            return helper(i+1 , j+1 , s , p);
        }
        return false;

    }
    bool isMatch(string s, string p) {
       return  helper(0,0,s,p);
    }
};