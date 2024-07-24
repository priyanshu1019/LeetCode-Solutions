class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> result;
        vector<pair<int,pair<int,int>>> temp;
        int n = nums.size();
        for(int i =0 ; i < n ; i++){
            int num = 0;
            int copy = nums[i];
            int up  = 0;
            if( copy == 0) num = mapping[0];
            while(copy){
                int rem = copy % 10;
                rem = mapping[rem];
                num = rem * pow(10 , up) + num;
                copy = copy / 10;
                up++;
            }
            temp.push_back({num , {i , nums[i]}});
        }

        sort(temp.begin() , temp.end());
        for(int i =0 ; i < temp.size() ; i++){
            result.push_back(temp[i].second.second);
        }
        return result;
    }
};