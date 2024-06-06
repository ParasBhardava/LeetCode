class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        map<int, int> count;
        for (int it : hand)
            count[it]++;
        
        for (auto it : count)
        {
            if (count[it.first] > 0)
            {
                for (int i = groupSize - 1; i > 0; i--)
                {
                    int require = count[it.first + i] - count[it.first];
                    if (require < 0)
                        return false;
                    count[it.first + i] -= count[it.first];
                }
            }
        }
        return true;
    }
};