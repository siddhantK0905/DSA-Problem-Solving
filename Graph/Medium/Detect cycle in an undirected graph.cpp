//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        int vis[V]= {0};
        
        for(int i=0; i<V; i++){
            
            if(!vis[i]){
                if(detectCycle(i,adj, vis) == true) return true;
            }
        }
        
        return false;
    }
    
    bool detectCycle(int src, vector<int> adj[], int vis[]){
     
     vis[src] = 1;   // mark src node as visited
     queue<pair<int,int>>q;
     q.push({src, -1});  // insert into queue with parent node as -1
     
     while(!q.empty()){
         int node = q.front().first;
         int parent = q.front().second;
         q.pop();
         
         for(auto it:adj[node]){
             //if node is not visited
             if(!vis[it]){
                 vis[it] = 1;
                q.push({it,node}); 
             }
               //if node is already visited by same level node
             else if(it != parent){
                 return true;
             }
         }
     }
     
     return false;
    }
    
    //TC - O(N + 2E) + O(N)
    //SC - O(N)
};
