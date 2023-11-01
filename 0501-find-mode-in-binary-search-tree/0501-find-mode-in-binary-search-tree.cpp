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
    void inorder(TreeNode *root, int &maxFreq, int &currFreq, int &prev, vector<int>&res)
    {
        if (root == NULL)
            return;
        
        inorder(root->left, maxFreq, currFreq, prev, res);
        
        if (prev == root->val) 
            currFreq++;
        else
            currFreq = 1;
        if (currFreq > maxFreq)
        {
            res = {root->val};
            maxFreq = currFreq;
        }
        else if (currFreq == maxFreq)
            res.push_back(root->val);
        
        prev = root->val;
        inorder(root->right, maxFreq, currFreq, prev, res);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        vector<int>res;
        int maxFreq = 0, currFreq = 0, prev = INT_MIN;
        inorder(root, maxFreq, currFreq, prev, res);
        return res;
    }
};