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
    vector<int> solve(TreeNode* root, int &distance, int &res)
    {
        vector<int>count(distance + 1, 0);
        
        if(root == NULL)
            return count;
        
        if(root->left == NULL && root->right == NULL)
        {
            count[1]++;
            return count;
        }
        
        vector<int>left = solve(root->left, distance, res);
        vector<int>right = solve(root->right, distance, res);
        
        vector<int> rightPrefixSum(distance + 1, 0);
        rightPrefixSum[0] = right[0];
        for(int i = 1; i <= distance; i++)
            rightPrefixSum[i] = rightPrefixSum[i - 1] + right[i];
        
        for(int i = 0; i <= distance; i++)
            res += left[i] * rightPrefixSum[distance - i];
        
        for(int i = 0; i <= distance - 1; i++)
            count[i + 1] = left[i] + right[i];
        
        return count;
    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        solve(root, distance, res);
        return res;
    }
};