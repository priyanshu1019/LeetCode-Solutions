class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        vector<string> mp(1001 , "");
        mp[1] = "I";
        mp[4] = "IV";
        mp[5] = "V";
        mp[9] = "IX";
        mp[10] = "X";
        mp[40] = "XL";
        mp[50] = "L";
        mp[90] = "XC";
        mp[100] = "C";
        mp[400] = "CD";
        mp[500] = "D";
        mp[900] = "CM";
        mp[1000] = "M";

        for(int i =1000 ; i >= 1 ; i--){
            if( mp[i] == ""){
                continue;
            }
            int times = num  / i;
            for(int j = 0 ; j < times ; j++){
                result += mp[i];
            }
            num = num % i;
            if( num == 0 ) break;
        }

        return result;
    }
};