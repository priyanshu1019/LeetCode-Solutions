class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if( n!= m)return false;

        vector<int> freq1(26  ,0) , freq2(26 , 0);

        for(int i =0 ; i < n ; i++){
            int ind1 = word1[i]-'a';
            int ind2 = word2[i]-'a';

            freq1[ind1]++;
            freq2[ind2]++;
        }
        //first point
        for(int i =0 ; i < 26 ;i++){
            if( freq1[i]!= 0 and freq2[i]!= 0) continue;
            if( freq1[i] == 0 and freq2[i] == 0) continue;
            return false;
        }

        //second point;
        sort(freq1.begin() , freq1.end());
        sort(freq2.begin() , freq2.end());

        return freq1 == freq2;
    }
};