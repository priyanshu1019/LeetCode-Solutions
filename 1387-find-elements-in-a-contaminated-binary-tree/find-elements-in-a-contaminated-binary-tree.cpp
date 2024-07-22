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
class FindElements {
public:
    TreeNode* root;
    FindElements(TreeNode* root) {
        this->root = root;
    }
    bool helper(TreeNode* root , int target){
        if( root->val == target){
            return true;
        }
        if( root->left == NULL and root->right == NULL){
            return root->val == target;
        }
        int x = root->val;
        int right = false;
        if( root -> right){
            root->right->val = 2*x + 2;
            right = helper(root->right , target);
        }
        int left  = false;
        if( root -> left){
            root->left->val  = 2*x + 1;
            left  = helper(root->left , target);
        }
        return left || right;
    }
    bool find(int target) {
        root->val = 0;
        if( root ->val == target)return true;
        return helper(root , target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */