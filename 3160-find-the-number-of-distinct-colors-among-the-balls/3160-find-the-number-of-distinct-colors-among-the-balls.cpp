class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        unordered_map<int, int>ballToColor;
        unordered_map<int, int>colorCount;
        vector<int>res;
        
        for(auto query: queries){
            int ball = query[0];
            int color = query[1];
            
            if(ballToColor.count(ball)){
                int oldColor = ballToColor[ball];
                colorCount[oldColor]--;
                if(colorCount[oldColor] == 0)
                    colorCount.erase(oldColor);
            }
                
            ballToColor[ball] = color;
            colorCount[color]++;
            
            res.push_back(colorCount.size());
        }
        
        return res;
    }
};