class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        vector<int> count(26 , 0);
        for(char &ch:s){
            count[ch-'a'] = 1;
        }
        
        for(char first = 'a' ; first <='z' ; first++){
            for(char second = 'a' ; second<='z' ; second++){
                if( count[first-'a'] == 0 || count[second-'a'] == 0) continue;

                bool pastSecond = false;
                int firstCount  = 0;
                int secondCount = 0;
                for(char &ch:s){
                    if( ch == first) firstCount++;
                    if( ch == second) secondCount++;

                    if( secondCount > 0){
                        ans = max(ans , firstCount - secondCount);
                    }else{
                        if( pastSecond == true){
                            ans = max(ans , firstCount - 1);
                        }
                    }
                    if( secondCount > firstCount){
                        //reset but mark pastSecond true
                        pastSecond = true;
                        firstCount = 0;
                        secondCount= 0;
                    }
                }
            }
        }
        return ans;
    }
};