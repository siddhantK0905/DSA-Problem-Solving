/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj(100001);
       createGraph(root,adj);

        vector<int>vis(100001, 0);
        queue<int> q;
        q.push(start);
        int count = 0;

        while(!q.empty()){
           int k = q.size();

           while(k--){
                int node = q.front();
                q.pop();
                vis[node] = 1;
                
                for(int i=0; i< adj[node].size(); i++){
                    int it = adj[node][i];
                    if(vis[it]==0){
                        vis[it] =1;
                        q.push(it);
                    }
                }          
             }
           count++;
        }


       return count-1; 
    }

    void createGraph(TreeNode* root, vector<vector<int>>& adj){
        if(root == NULL) return ;

        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }

        createGraph(root->left, adj);
        createGraph(root->right, adj);
    }
};
