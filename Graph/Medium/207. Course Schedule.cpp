class Solution {
public:
    //Approach
    // Perform Topological sort by Kahn's algorithm
    // check the size of ans vector and given V if equal return true otherwise return false 

    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int>adj[V];

        for(auto it:prerequisites ){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(V,0);

        //Calculating indegree of all nodes
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        //push the nodes whose indgree is 0
        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            //degreasing degree of adjacent nodes of given NODE by 1
            for(auto it: adj[node]){
                indegree[it]--;
                //indegree with 0 push into the queue
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(ans.size() == V) return true;

        return false;

    }
};

//Time complexity -O(V+E)
//Space Complexity -O (V);
