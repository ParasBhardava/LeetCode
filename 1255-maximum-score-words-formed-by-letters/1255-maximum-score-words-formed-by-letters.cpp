class Solution {
    
private:
    int solve(int idx, int n, vector<string>& words, vector<char>& letters, vector<int>& score, unordered_map<char, int>&mp)
    {
        if(idx >= n)
            return 0;
        
        int possibleIdx = 0, take = 0, res = 0;
        for(possibleIdx = 0; possibleIdx < words[idx].size(); possibleIdx++)
        {
            char ch = words[idx][possibleIdx];
            if(mp[ch] == 0){
                res = 0;
                break;
            }
            mp[ch]--;
            res += score[ch - 'a'];
        }
        
        if(possibleIdx == words[idx].size())
            take = res + solve(idx + 1, n, words, letters, score, mp);
        
        for(int i = 0; i < possibleIdx; i++){
            char ch = words[idx][i];
            mp[ch]++;
        }
        
        int dontTake = solve(idx + 1, n, words, letters, score, mp);
        return max(take, dontTake);
    }
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int n = words.size();
        unordered_map<char, int>mp;
        for(char letter : letters)
            mp[letter]++;
        
        return solve(0, n, words, letters, score, mp);
    }
};