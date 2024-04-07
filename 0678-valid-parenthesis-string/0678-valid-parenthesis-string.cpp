class Solution {
public:
    bool checkValidString(string s) {
        int countMin = 0, countMax = 0;
        for (char ch : s) {
            if (ch == '(') {
                countMax++;
                countMin++;
            } 
            else if (ch == ')') {
                countMax--;
                countMin--;
            } else if (ch == '*') {
                countMax++;
                countMin--; 
            }
            if (countMax < 0) 
                return false; 
            countMin = max(countMin, 0);
        }
        return countMin == 0;
    }
};