class Trie
{
    
    struct Trienode
    {
        int cost = INT_MAX;
        Trienode *child[26];
    };

    Trienode *root;

public:
    Trienode *getNode()
    {
        Trienode *newnode = new Trienode();
        newnode->cost = INT_MAX;

        for (int i = 0; i < 26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

    Trie()
    {
        root = getNode();
    }

    void insert(string &word, int cost)
    {
        Trienode *curr = root;
        int index;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = getNode();

            curr = curr->child[index];
        }

        curr->cost = min(curr->cost, cost);
    }

    bool search(string &word)
    {
        Trienode *curr = root;
        int index;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                return INT_MAX;

            curr = curr->child[index];
        }

        return curr->cost;
    }
    
    int findCost(string &target)
    {
        int n = target.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; 
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == INT_MAX)
                continue; 

            Trienode* curr = root;
            for (int j = i; j < n; j++)
            {
                int idx = target[j] - 'a';
                if (curr->child[idx] == NULL)
                    break;  

                curr = curr->child[idx];
                if (curr->cost != INT_MAX)
                    dp[j + 1] = min(dp[j + 1], dp[i] + curr->cost);
            }
        }
        
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
    
};



class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        
        Trie *t = new Trie();
        for(int i = 0;  i < words.size(); i++){
            t->insert(words[i], costs[i]);
        }
        
        return  t->findCost(target);
    }
};