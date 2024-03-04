class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size(),  i = 0, j = n - 1, count = 0, res = 0;
        sort(tokens.begin(), tokens.end());
        
        while(i <= j)
        {
            if(power >= tokens[i])
            {
                power -= tokens[i];
                i++;
                count++;
                res = max(res, count);
            }
            
            else if(count > 0)
            {
                power += tokens[j];
                j--;
                count--;
            }
            
            else
                break;
        }
        
        return res;
    }
};