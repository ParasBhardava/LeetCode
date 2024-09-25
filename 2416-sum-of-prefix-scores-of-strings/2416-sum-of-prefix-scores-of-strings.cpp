
class Trie
{
    struct Trienode
    {
        bool endsHere;
        Trienode *child[26];
        int count;
    };

    Trienode *root;

    Trienode *getNode()
    {
        Trienode *newnode = new Trienode();
        newnode->endsHere = false;
        newnode->count = 0;

        for (int i = 0; i < 26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

public:
    Trie()
    {
        root = getNode();
    }

    void insert(string &word)
    {
        Trienode *curr = root;
        int idx;

        for (char ch : word)
        {
            idx = ch - 'a';
            if (curr->child[idx] == NULL)
                curr->child[idx] = getNode();

            curr = curr->child[idx];
            curr->count++;
        }
        
        curr->endsHere = true;
    }
    
    int count(string &word)
    {
        Trienode *curr = root;
        int idx;
        
        int count = 0;
        for(char ch : word)
        {
            idx = ch - 'a';
            curr = curr->child[idx];
            count += curr->count;
            
        }
        
        return count;
    }
};


class Solution {
    
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        
        Trie *t = new Trie();
        int n = words.size();
        for(int i = 0; i < n; i++)
            t->insert(words[i]);
        
        vector<int>res(n, 0);
        for(int i = 0; i < n; i++)
            res[i] = t->count(words[i]);
        
        return res;
        
    }
};