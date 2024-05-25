class Solution {
public:
    class Trie
    {
        struct Trienode
        {
            char val;
            int endsHere;
            Trienode *child[26];
        };

        Trienode *getNode(char ch)
        {
            Trienode *newnode = new Trienode();
            newnode->val = ch;
            newnode->endsHere = 0;
            for (int i = 0; i < 26; i++)
                newnode->child[i] = NULL;

            return newnode;
        }

    public:
        Trienode *root = getNode('/');

        void insert(string word)
        {
            Trienode *curr = root;
            int index;

            for(int i = 0; i<word.size(); i++)
            {
                index = word[i] - 'a';
                if(curr->child[index] == NULL)
                    curr->child[index] = getNode(word[i]);

                curr = curr->child[index];
            }

            curr->endsHere += 1;
        }

        bool search(string word)
        {
            Trienode *curr = root;
            int index;

            for(int i = 0; i<word.size(); i++)
            {
                index = word[i] - 'a';

                if(curr->child[index] == NULL)
                    return false;

                curr = curr->child[index];
            }

            return curr->endsHere > 0;
        }
    };

    
    void solve(string &s, string ans, int pos, Trie *root, vector<string> &res)
    {
        if(pos == s.size())
        {
            res.push_back(ans);
            return;
        }

        ans += " ";
        for(int i = pos; i<s.size(); i++)
        {
            if(root->search(s.substr(pos, i+1-pos)))
                solve(s, ans+s.substr(pos, i+1-pos), i+1, root, res);
        }

    }

    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie *root = new Trie();
        for(string &str : wordDict)
            root->insert(str);

        vector<string>res;
        for(int i = 0; i<s.size(); i++)
        {
            if(root->search(s.substr(0, i+1)))
                solve(s, s.substr(0, i+1), i+1, root, res);
        }

        return res;
    }
};