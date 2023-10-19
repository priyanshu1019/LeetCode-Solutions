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
    int maxLevelSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        int level  = 0;
        int ans =0;
        queue< TreeNode* > q;
        q.push(root);
        
        while ( !q.empty( )){
            level++;
            int len = q.size();
            int levelSum =0;
            while( len--){
                
                TreeNode* currNode = q.front();
                q.pop();
                levelSum += currNode -> val;
                
                if( currNode -> left){
                    q.push( currNode -> left);
                }
                if( currNode -> right ){
                    q.push( currNode -> right);
                }
        
            }
            if( levelSum > maxSum){
                maxSum = levelSum;
                ans = level;
            }
            
        } 
        return ans;
        
    }
};