class Trie
{
private:
    struct Trienode
    {
        char val;
        int endsHere;
        Trienode *child[26];
    };

    Trienode* root;

    Trienode * getNode(char ch)
    {
        Trienode *newnode = new Trienode;
        newnode->val = ch;
        newnode->endsHere = 0;
        for(int i = 0; i<26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

public:
    Trie()
    {
        root = getNode('/');
    }

    void insert(string word)
    {
        Trienode *curr = root;
        int index;

        for(int i = 0; i<word.size(); i++)
        {
            index = word[i]-'a';
            if(curr->child[index] == NULL)
                curr->child[index] = getNode(word[i]);

            curr = curr->child[index];
        }

        curr->endsHere += 1;
    }

    string search(string word)
    {
        Trienode *curr = root;
        int index;
        if(curr->child[word[0]-'a'] == NULL)
            return word;

        string res = "";

        for(int i = 0; i<word.size(); i++)
        {
            index = word[i]-'a';
            if(curr->child[index] == NULL)
                return word;

            res.push_back(curr->child[index]->val);

            if(curr->child[index]->endsHere > 0)
                return res;

            curr = curr->child[index];
        }

        return res;
    }

};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        string ans = "";
        Trie *t = new Trie();        
        for(int i = 0; i<dictionary.size(); i++)
            t->insert(dictionary[i]);
        
        stringstream ss(sentence); 
        string word; 
        
        while(ss >> word)
        {
            ans +=  t->search(word);
            ans += " ";
        }
        ans.pop_back();
        
        return ans;
    }
};