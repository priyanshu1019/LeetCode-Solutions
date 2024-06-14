class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0  , right = 0;
        int n = s.size();
        int maxLen = 0;
        int maxFreq = 0;
        unordered_map<char,int> freq;
        while(right<n)
        {
            freq[s[right]]++;
            maxFreq = max(maxFreq , freq[s[right]]);

            while((right-left + 1) - maxFreq > k)
            {
                freq[s[left]]--;
                maxFreq = 0;
                for(auto it:freq)
                {
                    maxFreq = max(maxFreq , it.second);
                }
                left++;
            }

            if( (right - left + 1) - maxFreq <=k)
            {
                maxLen = max(maxLen , right-left+1);
            }
            right++;
        }

        return maxLen;
    }
};