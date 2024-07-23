class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n    = bank.size();
        int m    = bank[0].size();
        int curr = 0;
        int prev = 0;
        int total= 0;

        for(int i =0 ; i < n ; i++){
            curr = 0;
            for(int j = 0 ; j < m ; j++){
                if( bank[i][j] == '1'){
                    curr++;
                }
            }
            if( curr != 0 and i != 0){
                total += (curr * prev);
            }
            if( curr != 0){
                prev = curr;
            }
        }

        return total;
    }
};