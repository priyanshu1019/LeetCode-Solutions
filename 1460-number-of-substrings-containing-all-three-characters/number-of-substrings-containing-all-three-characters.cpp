class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0 , right = 0 , count = 0 ;
        int lastSeen[] = {-1,-1,-1};
        while(right < n)
        {
            lastSeen[s[right] - 'a'] = right;

            if( lastSeen[0] != -1 and lastSeen[1]!= -1 and lastSeen[2] != -1){
                count = count + 1+ min(lastSeen[0] ,min(lastSeen[1] , lastSeen[2]));
            }
            right++;
        }
    return count;
    }

};