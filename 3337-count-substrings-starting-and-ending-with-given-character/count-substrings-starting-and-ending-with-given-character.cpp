class Solution {
public:
    long long countSubstrings(string s, char c) {
        
        long long  count = 0;
        
        for(auto ch:s)
        {
            if ( ch == c )
            {
                count++;
            }
        }
        long long val = count*(count+1);
        val = val / 2;
        return val;
    }
};