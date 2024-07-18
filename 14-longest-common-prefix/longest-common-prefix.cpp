class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n         = strs.size();
        if( n == 0) return "";
        if( n == 1) return strs[0];
        string result = strs[0];
        int len       = result.size();

        for(int i = 1; i < n; i++){
            while(strs[i].find(result)!= 0){
                result = result.substr(0 , len-1);
                len--;
                if( len == 0){
                    return "";
                }
            }
        }
        return result;

    }
};