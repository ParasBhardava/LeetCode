class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char> vowels;
        unordered_set<char>st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for(int i = 0; i < n; i++)
        {
            if(st.count(s[i]))
                vowels.push_back(s[i]);
        }
        
        int k = 0;
        sort(vowels.begin(), vowels.end());
        for(int i = 0; i < n; i++)
        {
            if(st.count(s[i]))
                s[i] = vowels[k++];
        }
        return s;
    }
};