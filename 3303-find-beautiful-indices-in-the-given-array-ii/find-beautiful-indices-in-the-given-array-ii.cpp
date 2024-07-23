class Solution {
private:
    void computeLps(string &pat , vector<int>&lps){
        lps[0] = 0;
        int M  = pat.size();
        int len= 0;
        int i  = 1;

        while( i < M ){
            if( pat[i] == pat[len]){
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
    vector<int> KMP(string &txt , string &pat){
        int N = txt.size();
        int M = pat.size();
        int i = 0;
        int j = 0;

        vector<int> result;
        vector<int> lps(M , 0);
        computeLps(pat , lps);

        while( i < N ){
            if( txt[i] == pat[j]){
                i++;
                j++;
            }
            if(j == M ){
                result.push_back(i-M);
                j = lps[j-1];
            }else if( txt[i] != pat[j]){
                if( j!= 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return result;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> result;
        vector<int> i_indices = KMP(s , a);
        vector<int> j_indices = KMP(s , b);
        int n  = s.size();

        for(int &i: i_indices){
            int leftLimit = max(0 , i-k);
            int rightLimit= min(n-1 , i+k);

            auto it = lower_bound(begin(j_indices) , end(j_indices) , leftLimit);

            if( it != j_indices.end() and *it <= rightLimit){
                result.push_back(i);
            }
        }

        return result;
    }
};