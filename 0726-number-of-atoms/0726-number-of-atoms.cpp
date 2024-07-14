class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        unordered_map<string, int> resCount;
        stack<unordered_map<string, int>> st;
        int currIdx = 0;

        while (currIdx < n)
        {
            char currChar = formula[currIdx];

            if (currChar == '(')
            {
                currIdx++;
                st.push(unordered_map<string, int>());
                continue;
            }

            if (currChar == ')')
            {
                string multStr = "";
                currIdx++;

                while (currIdx < n && isdigit(formula[currIdx]))
                {
                    multStr += formula[currIdx];
                    currIdx++;
                }

                int mult = multStr.empty() ? 1 : stoi(multStr);
                
                unordered_map<string, int> lastCount = st.top();
                st.pop();
                unordered_map<string, int>& target = st.empty() ? resCount : st.top();
                
                for (auto it : lastCount)
                    target[it.first] += it.second * mult;
        
                continue;
            }

            string currElement = "";
            string curCounterStr = "";
            unordered_map<string, int>& target = st.empty() ? resCount : st.top();

            while (currIdx < n && formula[currIdx] != '(' && formula[currIdx] != ')') 
            {
                if (isalpha(formula[currIdx])) 
                {
                    if (isupper(formula[currIdx]) && !currElement.empty())
                    {
                        target[currElement] += curCounterStr.empty() ? 1 : stoi(curCounterStr);
                        currElement = "";
                        curCounterStr = "";
                    }
                    currElement += formula[currIdx];
                } 
                else
                    curCounterStr += formula[currIdx];
                
                currIdx++;
            }

            target[currElement] += curCounterStr.empty() ? 1 : stoi(curCounterStr);
        }

        vector<string> parts;
        for (auto it : resCount)
            parts.push_back(it.first + (it.second == 1 ? "" : to_string(it.second)));
        sort(parts.begin(), parts.end());
       
        string res;
        for (auto part : parts)
            res += part;

        return res;
    }
};