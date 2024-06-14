class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if( s.size() == 0 || s.size() == 1)  return s.size();
        int l = 0 ;
        int r = 0;
        int n = s.size();
        int maxLen = 0;
        //char found at index
        unordered_map<char,int> mp;
        
        while(r<n )
        {
            if( mp.find(s[r]) != mp.end())
            {
                if( mp[s[r]] >= l )

                    l = mp[s[r]]+1;
            }
            maxLen = max(maxLen , r-l+1);
            mp[s[r]] = r;
            r++;
        }
        return  maxLen;
    }
};