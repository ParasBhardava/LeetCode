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
    TreeNode* solve(TreeNode *node, unordered_set<int>&deleteNodes, vector<TreeNode*>&res)
    {
        if(node == NULL)
            return NULL;
        
        node->left = solve(node->left, deleteNodes, res);
        node->right = solve(node->right, deleteNodes, res);
        
        if(deleteNodes.count(node->val))
        {
            if (node->left != NULL)
                res.push_back(node->left);
            if (node->right != NULL)
                res.push_back(node->right);
            return NULL;
        }
        
        return node;
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>deleteNodes;
        for(int node : to_delete)
            deleteNodes.insert(node);
        vector<TreeNode*>res;
        
        if(!deleteNodes.count(root->val))
            res.push_back(root);
        solve(root, deleteNodes, res);
        return res;
    }
};