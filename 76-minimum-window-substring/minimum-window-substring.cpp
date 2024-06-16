class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }
        int requiredCount = t.size();
        int left = 0, right = 0;
        int start_i = 0;
        int minWindowSize = INT_MAX;

        while (right < n) {
            char ch = s[right];
            if (mp[ch] > 0) requiredCount--;
            mp[ch]--;

            while (requiredCount == 0) {
                int currWindowSize = right - left + 1;
                if (currWindowSize < minWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = left; // will be used to get the substring
                }

                mp[s[left]]++;
                if (mp[s[left]] > 0) {
                    requiredCount++;
                }
                left++;
            }

            right++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};
