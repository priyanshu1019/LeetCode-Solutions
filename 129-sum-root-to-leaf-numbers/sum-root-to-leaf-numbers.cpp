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
    int helper(TreeNode* root  , int number ){
        
        if( root->left == NULL and root->right == NULL ){
            number = number * 10 + root->val;
            return number;
        }


        int left = 0;
        if( root->left ){

           left = helper(root->left , number*10+root->val);
        }
        int right = 0;
        if( root -> right ){

            right= helper(root->right , number * 10 + root->val);
        }

        return left+right;
    }
public:
    int sumNumbers(TreeNode* root) {
        int number = 0;
        if( root == NULL ) return 0;
        return helper(root  , number);
    }
};