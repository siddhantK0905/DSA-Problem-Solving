class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1);

      //if there is connected components
        for(int i=0; i<n; i++){
            if(vis[i]== -1){
                if(check(i, vis, graph) == false) return false;
            }
        }

        return true;
    }


    bool check(int start , vector<int> &vis, vector<vector<int>>& graph){
        vis[start] =0;
        queue<int> q; 
        q.push(start);

         while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: graph[node]){
              //if node is not coloured
                if(vis[it] == -1){
                  //coloured with altenate with there parent node
                    vis[it] = !vis[node]; 
                    q.push(it);
                }
                  //if node is already coloured by other node & having same color of parent node then it is not Bipartite graph
                else if(vis[it] == vis[node]){
                    return false;
                }
            }
        }

        return true;

    }
};

//Space complexity = O(V)
//Time Complexity = O(V + 2E) + O(N)
