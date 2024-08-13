class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(int x:arr){
            mp[x]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int req = arr.size()/2;
        int cnt=0;
        while(!pq.empty()){
            cnt++;
            req -= pq.top().first;
            if( req <= 0) {
                return cnt;
            }
            pq.pop();
        }
        return -1;
    }
};