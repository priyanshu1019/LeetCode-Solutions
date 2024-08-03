class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int freq[1001]={0};
        for(int i =0 ; i < target.size() ; i++){
            freq[target[i]]++;
            freq[arr[i]]--;
        }
        for(int i =0 ; i < 1001 ; i++){
            if( freq[i] != 0) return false;
        }
        return true;
    }
};