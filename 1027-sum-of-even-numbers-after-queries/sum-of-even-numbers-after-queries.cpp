class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        int sum = 0;
        int n   = nums.size();

        for(auto &num : nums)
        {
            if(num % 2 == 0)
            {
                sum += num;
            }
        }
        for(auto &querie : queries)
        {
            int valuei = querie[0];
            int indexi = querie[1];
            int initValue = nums[indexi];
            if( initValue % 2 == 0)
            {
                //even 
                sum -= initValue;
            }
            nums[indexi] = nums[indexi]+ valuei;
            if( nums[indexi] % 2 == 0)
            {
                sum += nums[indexi];
            }
            answer.push_back(sum);
        }
        return answer;

        
    }
};