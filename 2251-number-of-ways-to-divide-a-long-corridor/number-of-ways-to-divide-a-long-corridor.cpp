class Solution {
public:
    int MOD = 1e9+7;
    int numberOfWays(string corridor) {
        int n = corridor.size();
        long long  result = 1;
        vector<int> indices;

        for(int i =0 ; i < n ; i++){
            if( corridor[i] == 'S'){
                indices.push_back(i);
            }
        }
        if(indices.size()  % 2 != 0 || indices.size() == 0){
            return 0;
        }
        long long  prevSectionLastInd = indices[1];
        for(int i = 2; i < indices.size() ; i+=2){
            int len = indices[i] - prevSectionLastInd;
            result = (result * len) % MOD;
            prevSectionLastInd = indices[i+1];
        }

        return result;
    }
};