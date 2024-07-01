class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int n = arr.size();
        int oddsCount = 0;
        for (int i = 0; i < n && oddsCount < 3; i++)
            oddsCount = arr[i] % 2 ? oddsCount + 1 : 0;
    
        return oddsCount == 3;
    }
};