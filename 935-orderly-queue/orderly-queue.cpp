class Solution {
public:
    string orderlyQueue(string s, int k) {
        if( k > 1){
            sort(s.begin() , s.end());
            return s;
        }
        string result = s;
        for(int l = 1; l <= s.size() - 1 ; l++ ){
            string temp = s.substr(l) + s.substr(0 , l);
            result = min(temp , result);
        }
        return result;
    }
};