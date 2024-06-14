class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> freq;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        
        while(r< n)
        {
            freq[fruits[r]]++;
            
            while(freq.size()> 2)
            {
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0) freq.erase(fruits[l]);
                
                l++;
            }
            
            maxLen = max(maxLen , r-l+1);
            r++;
        }
        
        return maxLen;
    }
};