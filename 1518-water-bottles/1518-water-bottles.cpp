class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int fullBottles = numBottles, emptyBottles = 0, res = 0;
        while(fullBottles)
        {
            res += fullBottles;
            fullBottles = numBottles / numExchange;
            emptyBottles = numBottles % numExchange;
            numBottles = fullBottles + emptyBottles;
        }
        return res;
    }
};