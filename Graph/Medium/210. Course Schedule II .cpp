class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        
        vector<int>topo;
        vector<int>indegree(V,0);
        vector<int> adj[V];
 
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]); 
        }

        //Calculating indegree
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){

            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        vector<int> ans;
        if(topo.size() == V){
            for(int i=topo.size()-1; i>=0; i--){
                ans.push_back(topo[i]);
            }
        return ans;
        } 

        return {};
    }
};
