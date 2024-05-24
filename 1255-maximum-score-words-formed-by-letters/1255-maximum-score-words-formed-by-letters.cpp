class Solution {
    
private:
    int solve(int idx, int n, vector<string>& words, vector<char>& letters, vector<int>& score, map<char, int>&count, map<pair<int, map<char, int>>, int>&dp)
    {
        if(idx >= n)
            return 0;
        
        if(dp.find({idx, count}) != dp.end())
            return dp[{idx, count}];
        
        int possibleIdx = 0, take = 0, res = 0;
        for(possibleIdx = 0; possibleIdx < words[idx].size(); possibleIdx++)
        {
            char ch = words[idx][possibleIdx];
            if(count[ch] == 0){
                res = 0;
                break;
            }
            count[ch]--;
            res += score[ch - 'a'];
        }
        
        if(possibleIdx == words[idx].size())
            take = res + solve(idx + 1, n, words, letters, score, count, dp);
        
        for(int i = 0; i < possibleIdx; i++){
            char ch = words[idx][i];
            count[ch]++;
        }
        
        int dontTake = solve(idx + 1, n, words, letters, score, count, dp);
        return dp[{idx, count}] = max(take, dontTake);
    }
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int n = words.size();
        map<char, int>count;
        for(char letter : letters)
            count[letter]++;
        
        map<pair<int, map<char, int>>, int>dp;
        return solve(0, n, words, letters, score, count, dp);
    }
};