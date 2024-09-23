/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root , TreeNode* p , TreeNode* q){
        if( root == NULL )return NULL;

        if( root == p || root == q){
            return root;
        }
        TreeNode* leftRec = NULL ;
        TreeNode* rightRec = NULL;
        if( root->left){
            leftRec = solve(root->left , p , q);
        }
        if( root->right){
            rightRec = solve(root->right , p , q);
        }
        return ( leftRec ? (rightRec ? root:leftRec):rightRec);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root , p , q);
    }
};