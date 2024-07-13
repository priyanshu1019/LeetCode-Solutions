class Solution {
public:
    string minWindow(string s, string t) {
        int requiredCount = t.size();
        unordered_map<char , int> mp;
        for(char ch:t){
            mp[ch]++;
        }

        int start_i =0 ;
        int left =0 , right = 0;

        int n = s.size();
        int miniWindow = INT_MAX;
        while(right < n ){
            char ch = s[right];
            if( mp[ch] > 0 ) {
                requiredCount--;
            }
            mp[ch]--;

            while(requiredCount == 0){
                int currentWindow = right - left +1;
                if( currentWindow < miniWindow){
                    miniWindow = currentWindow;
                    start_i = left;
                }

                mp[s[left]]++;
                if( mp[s[left]] > 0 ){
                    requiredCount++;
                }
                left++;
            }
            right ++;
        }
        return miniWindow == INT_MAX ? "":s.substr(start_i , miniWindow);
    }
};