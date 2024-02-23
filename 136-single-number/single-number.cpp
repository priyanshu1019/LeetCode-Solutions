class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> countOf;
        for(auto it: nums)
        {
            countOf[it]++;
        }
        for(auto it:countOf)
        {
            if(it.second==1)
            {
                return it.first;
            }
        }
        return -1;
    }
};