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
    int maxSum;
    
    int helper( TreeNode* root ){
        
        //what will you return as sum if there is no node?
        if( root == NULL ) 
            return 0;
        
        //get left and right sum 
        int leftSum  = helper( root -> left  );
        int rightSum = helper( root -> right );
        
        //3 possibilities ---1. leftSum better or rightSum better ---2.root better ---3. together they are better(togetherForever)
        int togetherForever   = leftSum + rightSum + root -> val;
        int leftOrRightBetter = max( leftSum , rightSum ) + root -> val;
        int rootBetter        = root -> val;
        
        //update maxSum
        maxSum = max( { maxSum , togetherForever , leftOrRightBetter , rootBetter });
        
        //what should we return for upper function calls ? obvly a path either ----- 1. leftSum +root->val ----2. rightSum + root ->val ------3. root;
        return max( leftOrRightBetter , rootBetter );
        
    }
    int maxPathSum(TreeNode* root) {
        
        maxSum = INT_MIN;
        
        helper( root );
        
        return maxSum;
        
    }
};