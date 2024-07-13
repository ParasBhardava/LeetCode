class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        string moreOptimalString, lessOptimalString;
        int moreOptimalScore, lessOptimalScore;

        if (x >= y) 
        {
            moreOptimalString = "ab";
            moreOptimalScore = x;
            lessOptimalString = "ba";
            lessOptimalScore = y;
        } 
        else
        {
            moreOptimalString = "ba";
            moreOptimalScore = y;
            lessOptimalString = "ab";
            lessOptimalScore = x;
        }
        
        string res1 = "";
        for (char ch : s) 
        {
            if (ch == moreOptimalString[1] && !res1.empty() &&
                res1.back() == moreOptimalString[0]) 
            {
                score += moreOptimalScore;
                res1.pop_back();
            } 
            else
                res1.push_back(ch);
        }

        string res2 = "";
        for (char ch : res1) 
        {
            if (ch == lessOptimalString[1] && !res2.empty() && res2.back() == lessOptimalString[0]) 
            {
                score += lessOptimalScore;
                res2.pop_back();
            } 
            else
                res2.push_back(ch);
        }

        return score;
    }
};