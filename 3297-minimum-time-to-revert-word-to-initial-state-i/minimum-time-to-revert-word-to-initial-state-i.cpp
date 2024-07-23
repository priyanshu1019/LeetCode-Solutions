class Solution {
    void computeLps(string &pat , vector<int> &lps){
        lps[0] = 0;
        int i  = 1;
        int M  = pat.size();
        int len= 0;

        while( i < M ){
            if( pat[len] == pat[i]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if( len != 0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int> lps(n );
        computeLps(word , lps);

        int suffLength = lps[n-1];

        while(suffLength > 0 and (n-suffLength) % k != 0){
            suffLength = lps[suffLength-1];
        }  

        if((n -suffLength ) % k == 0){
            return (n-suffLength) / k;
        }
        return ceil(n / (double)k);
    }
};