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
private:
    void helper(TreeNode* root1 , TreeNode* root2){
        if( root1 == NULL){
            return ;
        }
        if( root1->right){
            root2->left = new TreeNode(root1->right->val);
        }
        if( root1->left){
            root2->right = new TreeNode(root1->left->val);
        }
        helper(root1->left , root2->right);
        helper(root1->right , root2->left);
    }
public:
    TreeNode* invertTree(TreeNode* root1) {
        if( root1 == NULL )return NULL;
        TreeNode* root2 = new TreeNode(root1->val);
        helper(root1 , root2);
        return root2;
    }
};