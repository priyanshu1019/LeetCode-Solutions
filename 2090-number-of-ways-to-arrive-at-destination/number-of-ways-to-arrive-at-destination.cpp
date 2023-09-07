class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<long long> dist(n,1e18),ways(n,0);
        ways[0]=1;
        dist[0]=0;
        pq.push({0,0});
        long long mod=(int)(1e9+7);
        while(!pq.empty()){
            long long dis=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long adjNode=it.first;
                long long wt=it.second;
                if(wt+dis<dist[adjNode]){
                    dist[adjNode]=wt+dis;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                    //beacuse we are first time coming to this node with such 
                    //less distance
                }
                else if(wt+dis==dist[adjNode]){
                    //push karne ka koi sens nahi 
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};