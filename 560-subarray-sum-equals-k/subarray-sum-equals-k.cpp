class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count = 0;
        map<int , int > preSumMap;
        int j = 0;
        int sum = 0;
        preSumMap[0] = 1;
        while(j<nums.size()){
            sum+=nums[j];
            int rem = sum-k;
            if(preSumMap.find(rem) != preSumMap.end()){
                count += preSumMap[rem];
            }
            preSumMap[sum] +=1;
            j++;

        }

        return count;

    }
};