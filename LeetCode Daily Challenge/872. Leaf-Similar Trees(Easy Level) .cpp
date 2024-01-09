class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        checkRoot(root1, v1);
        checkRoot(root2, v2);

        if(v1.size() != v2.size()) return false;
        for(int i=0; i<v1.size(); i++){
            if(v1[i] != v2[i]) return false;
        }

        return true;
    }

    void checkRoot(TreeNode* root, vector<int> & v1){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            v1.push_back(root->val);
        }
        checkRoot(root->left, v1);
        checkRoot(root->right, v1);
    }
};

//Time Complexity - O(N)
//Space Complexity - O(N)
