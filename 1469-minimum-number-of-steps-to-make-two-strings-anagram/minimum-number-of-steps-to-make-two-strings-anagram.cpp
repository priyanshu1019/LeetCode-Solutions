class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26 , 0);
        int n = s.size();
        for(int i =0 ; i < n ; i++){
            int ind = s[i]-'a';
            freq[ind]++;
        }

        for(int i =0 ; i < n ; i++){
            int ind = t[i]-'a';
            if( freq[ind] > 0 )
                freq[ind]--;
        }
        int count = 0;

        for(int i =0 ; i < 26 ; i++){
            count += freq[i];
        }
        return count;
    }
};