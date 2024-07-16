class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> st;
        vector<int> ans;

        for(int &num : nums){
            if( st.find(num) != st.end()){
                ans.push_back(num);
            }else{
                st.insert(num);
            }
        }

        return ans;
    }
};