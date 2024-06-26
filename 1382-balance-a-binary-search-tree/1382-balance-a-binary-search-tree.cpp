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
    TreeNode * solve(vector<int>&arr, int start, int end)
    {
        if(start > end)
            return NULL;
        
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = solve(arr, start, mid - 1);
        root->right = solve(arr, mid + 1, end);
        
        return root;
    }
    
private:
    void inorder(TreeNode *root, vector<int>&arr)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int>arr;
        inorder(root, arr);

        return solve(arr, 0, arr.size()-1);
    }
};