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
    string getSubStringForSubtree( TreeNode* root , unordered_map< string , int > &mp , vector< TreeNode* > &result ){
        //NULL
        if( root == NULL ) return "N";
        
        string s = to_string( root -> val ) + "," + getSubStringForSubtree( root -> left , mp , result ) +","+ getSubStringForSubtree( root -> right , mp , result );
        
        //checking if duplicate
        if( mp[s] == 1){
            
            result.push_back( root );

        }
        mp[s]++;
        
        return s;
        
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector< TreeNode* > result;
        unordered_map<string , int> mp;
        
        getSubStringForSubtree( root , mp , result );
        
        return result ;
        
    }
};