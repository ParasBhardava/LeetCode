class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int n = piles.size();
        int k = piles.size()/3;
        int i = 1;
        sort(piles.begin(), piles.end(), greater<int>());
        
        int coins = 0;
        while(k--)
        {
            coins += piles[i];
            i +=2;
        }
        
        return coins;
    }
};