class Solution {
public:
    int compress(vector<char>& chars) {
        int ind = 0;
        int count = 0;
        char ch;
        for(int i =0 ; i< chars.size() ; i++){
            if( i == 0){
                ch = chars[i];
                count = 1;
            }else{
                if( chars[i-1] == chars[i]){
                    count++;
                }else{
                    chars[ind++] = ch;
                    if( count > 1){
                        string ctr = to_string(count);
                        for(auto c:ctr){
                            chars[ind++] = c;
                        }
                    }
                    ch = chars[i];
                    count = 1;
                }
            }
        }
        chars[ind++] = ch;
                    if( count > 1){
                        string ctr = to_string(count);
                        for(auto c:ctr){
                            chars[ind++] = c;
                        }
                    }
        return ind;
    }
};