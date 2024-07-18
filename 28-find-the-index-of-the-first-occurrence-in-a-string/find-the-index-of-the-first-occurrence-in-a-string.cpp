class Solution {
public:
    int strStr(string str1, string str2) {
        int i =0  , j = 0;
        int n = str1.size();
        int m = str2.size();
        while(i != n){
            if( str1[i+j] == str2[j]){
                j++;
                if( j == m )return i;
            }else{
                j = 0;
                i++;
            }
        }

        return -1;
    }
};