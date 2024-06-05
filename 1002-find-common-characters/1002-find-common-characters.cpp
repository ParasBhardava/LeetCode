class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
      
        int n = words.size();
        vector<string> res;
        sort(words.begin(), words.end(), [&](string &s1, string &s2){
            return s1.size() < s2.size();
        });
        
        for (char ch : words[0])
        {
            bool flag = true;
            for (int i = 1; i < n; i++)
            {
                if (words[i].find(ch) == string::npos) {
                    flag = false;
                    break;
                } else
                    words[i].erase(words[i].find(ch), 1);
            }
            
            if (flag)
                res.push_back(string(1, ch));
        }
        return res;
    }
};