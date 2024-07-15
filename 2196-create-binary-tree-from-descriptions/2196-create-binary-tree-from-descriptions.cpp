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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        
        unordered_map<int, TreeNode*>mp;
        unordered_map<int, int>indegree;
        
        for(auto &it: d)
        {
            int child = it[1];
            int parent = it[0];
            int left = it[2];
            
            if(mp.find(parent) != mp.end())
            {
                TreeNode *node = mp[parent];
                if(left == 1)
                {
                    
                    if(mp.find(child) != mp.end())
                    {
                        node->left = mp[child];
                        indegree[child]++;
                    }
                    
                    else
                    {
                        TreeNode *l = new TreeNode(it[1]);
                        mp[it[1]] = l;
                        node->left = l;
                        indegree[it[1]]++;
                    }
                }

                else
                {
                    if(mp.find(child) != mp.end())
                    {
                        node->right = mp[child];
                        indegree[child]++;
                    }
                    
                    else
                    {
                        TreeNode *r = new TreeNode(it[1]);
                        mp[it[1]] = r;
                        node->right = r;
                        indegree[it[1]]++;
                    }
                }
                
                continue;
            }
            
            TreeNode *node = new TreeNode(it[0]);
            mp[it[0]] = node;
            indegree[it[0]] = 0;
            if(left == 1)
            {
                if(mp.find(child) != mp.end())
                {
                    node->left = mp[child];
                    indegree[child]++;
                }
                
                else
                {
                    TreeNode *l = new TreeNode(it[1]);
                    mp[it[1]] = l;
                    node->left = l;
                    indegree[it[1]]++;
                }
            }
            
            else
            {
                if(mp.find(child) != mp.end())
                {
                    node->right = mp[child];
                    indegree[child]++;
                }
                
                else
                {
                    TreeNode *r = new TreeNode(it[1]);
                    mp[it[1]] = r;
                    node->right = r;
                    indegree[it[1]]++;
                }
            }
        }
        
        for(auto &it: indegree)
        {
            if(it.second == 0)
                return mp[it.first];
        }
        
        return NULL;
    }
};