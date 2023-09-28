class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mp){
            char ch=it.first;
            int frq=it.second;
            pq.push({frq,ch});

        }
        string ans="";
        while(pq.size()>0){
            int size=pq.top().first;
            for(int i=0;i<size;i++){
                ans+=pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};