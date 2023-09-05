class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> reverseAdj[graph.size()];
        vector<int> indegree(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                reverseAdj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> safeNodes;
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //till now we have already pushed the terminal nodes in the queue
        //we know that a terminal node is always safe node 
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it:reverseAdj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;

    }
};