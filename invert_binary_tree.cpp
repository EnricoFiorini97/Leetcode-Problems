/*
Given the root of a binary tree, invert the tree, and return its root.
*/*
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
class Solution 
{
    public:
        TreeNode* invertTree(TreeNode* root) 
        {
            if (!root || (!root->left && !root->right))
                return root;
            
            queue <TreeNode*> Q;
            Q.push(root);
            
            while (!Q.empty())
            {
                TreeNode* current = Q.front();
                TreeNode* tmp = current->left;
                current->left = current->right;
                current->right = tmp;
                
                if (current->left)
                    Q.push(current->left);
                
                if (current->right)
                    Q.push(current->right);
                
                Q.pop();
            }
            
            return root;
        }
};
