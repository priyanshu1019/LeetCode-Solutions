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
    vector<int> largestValues(TreeNode* root) {
        
        if( root == NULL ) return {};
        
        queue< TreeNode* > q;
        vector<int> maxRow;
        q.push(root);
        
        while( !q.empty() )
        {
            
            int len      = q.size();
            int levelMax = INT_MIN;
            
            while( len-- ){
                
                TreeNode* node = q.front();
                q.pop();
                levelMax = max( levelMax , node -> val );
                
                if( node -> left )  q.push( node->left );
                if( node -> right ) q.push( node-> right );
                
            }
            maxRow.push_back( levelMax);
            
        }
        
        return maxRow;
        
    }
};