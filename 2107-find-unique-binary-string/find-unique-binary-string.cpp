class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int> st;
        int n = nums.size();
        for(string &num : nums){
            //converting binary to int
            st.insert(stoi(num , 0 , 2));
        }
        string result ="";
        for(int num = 0 ; num <= n ; num++){
            if(st.find(num) == st.end()){
                result = bitset<16>(num).to_string();
                return result.substr(16-n , n);
            }
        }

        return "";
    }
};