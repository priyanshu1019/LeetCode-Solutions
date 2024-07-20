class Solution {
private:
    int n ;
    vector<string> result;
    bool isValid(string str){
        if( str[0] == '0')return false;
        int val = stoi(str);

        return val<=255;
    }
    void solve(string s , int idx , string ip , int parts){
        if( idx == n and parts == 4){
            //remove last .
            ip.pop_back();
            result.push_back(ip);
            return;
        }

        if( idx+1<=n){
            solve(s , idx+1 , ip +s.substr(idx , 1) +'.' , parts+1);
        }
        if( idx + 2 <= n and isValid(s.substr(idx , 2))){
            solve(s , idx+2 , ip+s.substr(idx , 2) +'.', parts+1);
        }
        if( idx + 3<= n and isValid(s.substr(idx , 3))){
            solve(s , idx+3 , ip+s.substr(idx , 3)+'.' , parts+1);
        }

    }
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        result.clear();
        string ip="";
        int idx = 0;
        int parts = 0;
        solve(s , idx , ip , parts );
        return result;
    }
};