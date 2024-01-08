class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum =0;

        inorder(root, low, high, sum);

        return sum;
    }

    void inorder(TreeNode* root, int low, int high, int &sum){
        if(root == NULL){
            return;
        }

        inorder(root->left, low, high, sum);
        if(root->val >= low && root->val <= high){
            sum += root->val;
        } 
        inorder(root->right, low, high, sum);
    }
};

//Space complexity - O(1)
//Time Complexity - O(N)
