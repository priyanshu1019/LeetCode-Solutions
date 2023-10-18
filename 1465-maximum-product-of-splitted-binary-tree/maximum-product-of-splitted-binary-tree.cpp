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
    long  sum =0;
    long maxP =0;
    int MOD = 1e9 +7;
    int calculateSum( TreeNode* root ){
        
        if( root == NULL ){
            
            return 0;
            
        }
        int left = calculateSum( root ->left);
        int right= calculateSum( root ->right);
        
        
        return sum = root->val + left + right;
        
    }
    
    int helper( TreeNode* root){
        
        if( root == NULL ) return 0;
        
        int leftSum = helper( root ->left  );
        int rightSum = helper(root ->right );
        long  subtreeSum = leftSum + rightSum + root ->val;
        long  remainingSum = sum - subtreeSum;
        //we can either remove left or right
        maxP = max ( maxP , subtreeSum * remainingSum ) ;
        
        return subtreeSum;
    }
public:
    int maxProduct(TreeNode* root) {
        if( root == NULL ) return 0;
        sum = calculateSum( root );
        maxP = 0;
        helper( root );
        return maxP % MOD;
        
    }
};