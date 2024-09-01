class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;  // To store the parent of each node
    
    void updateParent(TreeNode* root) {
        if (root == NULL) return;

        if (root->left != NULL) {
            mp[root->left] = root;
        }
        if (root->right != NULL) {
            mp[root->right] = root;
        }

        updateParent(root->left);
        updateParent(root->right);
    }

    TreeNode* findStart(TreeNode* root, int start) {
        if (root == NULL) return NULL;
        if (root->val == start) return root;

        TreeNode* leftSearch = findStart(root->left, start);
        if (leftSearch != NULL) return leftSearch;

        return findStart(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        if (root == NULL) return 0;

        mp[root] = NULL;  // Root has no parent
        updateParent(root);

        TreeNode* st = findStart(root, start);  // Find the start node

        queue<TreeNode*> q;
        q.push(st);

        unordered_set<TreeNode*> visited;
        visited.insert(st);

        int time = 0;

        // Perform BFS to simulate the infection spreading
        while (!q.empty()) {
            int size = q.size();
            bool infected = false;

            while (size--) {
                TreeNode* temp = q.front();
                q.pop();

                // Check the left child
                if (temp->left != NULL && visited.find(temp->left) == visited.end()) {
                    q.push(temp->left);
                    visited.insert(temp->left);
                    infected = true;
                }

                // Check the right child
                if (temp->right != NULL && visited.find(temp->right) == visited.end()) {
                    q.push(temp->right);
                    visited.insert(temp->right);
                    infected = true;
                }

                // Check the parent
                if (mp[temp] != NULL && visited.find(mp[temp]) == visited.end()) {
                    q.push(mp[temp]);
                    visited.insert(mp[temp]);
                    infected = true;
                }
            }

            // If at least one node got infected, increase the time
            if (infected) {
                time++;
            }
        }

        return time;
    }
};
